/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:42 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/02 13:13:42 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_base_obj	*parse_obj(char **fields, int fields_count);
static int			iterate_and_close_parser_file(t_scene_parser *parser);

t_scene	*parse_file(char *file_name)
{
	t_scene_parser	*args;
	t_scene			*scene;
	int				aux;

	args = get_scene_parser_args(file_name);
	if (args == NULL)
		return (NULL);
	args->fd = open(file_name, O_RDONLY);
	aux = iterate_and_close_parser_file(args);
	scene = args->scene;
	free(args);
	if (aux != 1)
	{
		if (scene != NULL)
			free_scene(args->scene);
		return (NULL);
	}
	return (scene);
}

static int	iterate_and_close_parser_file(t_scene_parser *parser)
{
	if (parser == NULL || parser->fd < 0)
		return (0);
	parser->line = get_next_line(parser->fd);
	while (parser->line != NULL)
	{
		parser->obj = parse_line(parser->line);
		if (parser->obj == NULL)
			break ;
		free(parser->line);
		parser->line = get_next_line(parser->fd);
	}
	close(parser->fd);
	parser->fd = -1;
	if (parser->line == NULL)
		return (0);
	free(parser->line);
	parser->line = NULL;
	return (1);
}

t_base_obj	*parse_line(char *line)
{
	char		**fields;
	int			fields_count;
	t_base_obj	*obj;

	fields = ft_split(line, ' ');
	if (fields == NULL)
		return (NULL);
	fields_count = 0;
	while (fields[fields_count] != NULL)
		fields_count++;
	if (fields_count == 0)
		return (NULL);
	obj = parse_obj(fields, fields_count);
	ft_clear_arr((void **) fields);
	return (obj);
}

t_obj_type	get_type_by_str(char *str)
{
	if (ft_strcmp(str, "A") == 0)
		return (AMBIENT_LIGHT);
	else if (ft_strcmp(str, "C") == 0)
		return (CAMERA);
	else if (ft_strcmp(str, "L") == 0)
		return (LIGHT);
	else if (ft_strcmp(str, "sp") == 0)
		return (SPHERE);
	else if (ft_strcmp(str, "cy") == 0)
		return (CYLINDER);
	else if (ft_strcmp(str, "pl") == 0)
		return (PLANE);
	else
		return (UNKNOWN);
}

static t_base_obj	*parse_obj(char **fields, int fields_count)
{
	t_obj_type	type;

	type = get_type_by_str(fields[0]);
	if (type == AMBIENT_LIGHT)
		return ((t_base_obj *) parse_ambient_light(fields, fields_count));
	else if (type == CAMERA)
		return ((t_base_obj *) parse_camera(fields, fields_count));
	else if (type == LIGHT)
		return ((t_base_obj *) parse_light(fields, fields_count));
	else if (type == SPHERE)
		return ((t_base_obj *) parse_sphere(fields, fields_count));
	else if (type == CYLINDER)
		return ((t_base_obj *) parse_cylinder(fields, fields_count));
	else if (type == PLANE)
		return ((t_base_obj *) parse_plane(fields, fields_count));
	return (NULL);
}
