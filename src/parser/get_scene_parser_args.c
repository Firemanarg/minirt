/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:10:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/11 18:10:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_obj_type	get_type_from_line(const char *line);
static int			is_valid_parser(t_scene_parser *parser);
static int			increment_counters(t_scene_parser *parser, t_obj_type type);
static int			iterate_over_lines(t_scene_parser *parser);

/**
 * @details Creates a new scene parser object and returns it. The returned parser
 * object is already validated and contains the scene object with allocated
 * arrays for lights and geometries.
 *
 * @param file_name The name of the file to be parsed.
*/
t_scene_parser	*get_scene_parser_args(char const *file_name)
{
	t_scene_parser	*parser;
	int				aux;

	parser = (t_scene_parser *) malloc(sizeof(t_scene_parser));
	*parser = (t_scene_parser){0, .fd = -1};
	parser->fd = open(file_name, O_RDONLY);
	if (parser->fd < 0)
		return (NULL);
	aux = iterate_over_lines(parser);
	close(parser->fd);
	parser->fd = -1;
	if (aux != 1 || !is_valid_parser(parser))
	{
		free(parser->scene);
		free(parser);
		return (NULL);
	}
	parser->scene = new_scene(parser->light_count, parser->geometry_count);
	return (parser);
}

static int	iterate_over_lines(t_scene_parser *parser)
{
	t_obj_type	type;
	char		*endl_ptr;

	if (parser == NULL)
		return (0);
	parser->line = get_next_line(parser->fd);
	while (parser->line != NULL)
	{
		endl_ptr = ft_strchr(parser->line, '\n');
		if (endl_ptr != NULL)
			*endl_ptr = 0;
		if ((parser->line)[0] != '\0')
		{
			type = get_type_from_line(parser->line);
			if (!increment_counters(parser, type))
				break ;
		}
		free(parser->line);
		parser->line = get_next_line(parser->fd);
	}
	if (parser->line == NULL)
		return (1);
	free(parser->line);
	parser->line = NULL;
	return (0);
}

static t_obj_type	get_type_from_line(const char *line)
{
	char		*tmp;
	t_obj_type	type;

	tmp = ft_strchr(line, ' ');
	if (tmp == NULL)
		return (UNKNOWN);
	tmp = ft_strndup(line, tmp - line);
	type = get_type_by_str(tmp);
	free(tmp);
	return (type);
}

static int	is_valid_parser(t_scene_parser *parser)
{
	if (parser == NULL)
		return (0);
	else if (parser->scene == NULL)
		return (0);
	else if (parser->amb_light_count != 1)
		return (0);
	else if (parser->camera_count != 1)
		return (0);
	else if (parser->light_count <= 0)
		return (0);
	else if (parser->geometry_count <= 0)
		return (0);
	return (1);
}

static int	increment_counters(t_scene_parser *parser, t_obj_type type)
{
	if (type == CAMERA)
		parser->camera_count += 1;
	else if (type == LIGHT)
		parser->light_count += 1;
	else if (type == AMBIENT_LIGHT)
		parser->amb_light_count += 1;
	else if (type == SPHERE || type == CYLINDER || type == PLANE)
		parser->geometry_count += 1;
	else
		return (0);
	return (1);
}
