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

static int	type_is_geom(t_obj_type obj);
static t_obj_type	get_type_from_line(const char *line);
static void	*free_scene_parser(t_scene_parser *parser);
static int	increment_counters(t_scene_parser *parser, t_obj_type type);

t_scene_parser	*get_scene_parser_args(char const *file_name)
{
	t_scene_parser	*parser;
	t_obj_type		type;

	parser = (t_scene_parser *) malloc(sizeof(t_scene_parser));
	*parser = (t_scene_parser) {0};
	parser->scene = (t_scene *) malloc(sizeof(t_scene));
	parser->fd = open(file_name, O_RDONLY);
	if (parser->fd < 0)
		return (NULL);
	parser->line = get_next_line(parser->fd);
	while (parser->line != NULL)
	{
		type = get_type_from_line(line);
		if (!increment_counters(parser, type))
			return (free_scene_parser(parser));
		free(parser->line);
		parser->line = get_next_line(parser->fd);
	}
	free(parser->line);
	parser->line = NULL;
	parser->fd = -1;
	close(parser->fd);
	return (parser);
}

static int	type_is_geom(t_obj_type type)
{
	if (type == SPHERE || type == CYLINDER || type == PLANE)
		return (1);
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

static void	*free_scene_parser(t_scene_parser *parser)
{
	free(parser->scene);
	free(parser);
	return (NULL);
}

static int	increment_counters(t_scene_parser *parser, t_obj_type type)
{
	if (type == CAMERA)
		parser->camera_count += 1;
	else if (type == LIGHT)
		parser->light_count += 1;
	else if (type == AMBIENT_LIGHT)
		parser->amb_light_count += 1;
	else if (type_is_geom(type))
		parser->geometry_count += 1;
	else
		return (0);
	return (1);
}
