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

static t_err		parse_line(t_scene_parser *parser);
static t_err		parse_obj(char **fields, int fields_count,
						t_scene_parser *parser);
static int			iterate_and_close_parser_file(t_scene_parser *parser);
static t_err		add_to_scene(t_scene_parser *parser);

t_scene	*parse_file(char *file_name)
{
	t_scene_parser	*args;
	t_scene			*scene;
	int				aux;

	args = get_scene_parser_args(file_name);
	if (args == NULL)
		return (NULL);
	if (args->scene == NULL)
	{
		free(args);
		return (NULL);
	}
	args->fd = open(file_name, O_RDONLY);
	aux = iterate_and_close_parser_file(args);
	scene = args->scene;
	free(args);
	if (aux != 1)
	{
		if (scene != NULL)
			free_scene(scene);
		return (NULL);
	}
	return (scene);
}

static t_err	parse_line(t_scene_parser *parser)
{
	char		**fields;
	char		*endl_ptr;
	int			fields_count;
	t_err		err;

	endl_ptr = ft_strchr(parser->line, '\n');
	if (endl_ptr != NULL)
		*endl_ptr = '\0';
	if (parser->line[0] == '\0')
		return (OK);
	fields = ft_split(parser->line, ' ');
	if (fields == NULL)
		return (INVALID_ARG);
	fields_count = 0;
	while (fields[fields_count] != NULL)
		fields_count++;
	if (fields_count == 0)
	{
		free(fields);
		return (INVALID_ARG);
	}
	err = parse_obj(fields, fields_count, parser);
	ft_clear_arr((void **) fields, NULL);
	return (err);
}

static int	iterate_and_close_parser_file(t_scene_parser *parser)
{
	t_err	err;

	if (parser == NULL || parser->fd < 0)
		return (0);
	parser->line = get_next_line(parser->fd);
	while (parser->line != NULL)
	{
		err = parse_line(parser);
		if (err != OK || parser->line[0] != '\0')
			err |= add_to_scene(parser);
		if (err != OK)
			break ;
		free(parser->line);
		parser->line = get_next_line(parser->fd);
	}
	close(parser->fd);
	parser->fd = -1;
	if (parser->line == NULL)
		return (1);
	free(parser->line);
	parser->line = NULL;
	return (0);
}

static t_err	parse_obj(char **fields, int fields_count,
		t_scene_parser *parser)
{
	t_obj_type	type;

	parser->obj = (t_def_obj){0};
	type = get_type_by_str(fields[0]);
	if (type == AMBIENT_LIGHT)
		return (parse_ambient_light(fields, fields_count,
				(t_ambient_light *) &parser->obj));
	else if (type == CAMERA)
		return (parse_camera(fields, fields_count,
				(t_camera *) &parser->obj));
	else if (type == LIGHT)
		return (parse_light(fields, fields_count,
				(t_point_light *) &parser->obj));
	else if (type == SPHERE)
		return (parse_sphere(fields, fields_count,
				(t_sphere *) &parser->obj));
	else if (type == CYLINDER)
		return (parse_cylinder(fields, fields_count,
				(t_cylinder *) &parser->obj));
	else if (type == PLANE)
		return (parse_plane(fields, fields_count,
				(t_plane *) &parser->obj));
	return (INVALID_ARG);
}

static t_err	add_to_scene(t_scene_parser *parser)
{
	t_obj_type	type;

	type = parser->obj.b.type;
	if (type == AMBIENT_LIGHT)
		parser->scene->ambient_light = *((t_ambient_light *) &parser->obj);
	else if (type == CAMERA)
		parser->scene->camera = *((t_camera *) &parser->obj);
	else if (type == LIGHT)
	{
		parser->scene->lights[parser->light_index] = (
				*((t_point_light *) &parser->obj));
		parser->light_index += 1;
	}
	else if (type == SPHERE || type == CYLINDER || type == PLANE)
	{
		parser->scene->geometries[parser->geometry_index] = (
				*((t_geom_obj *) &parser->obj));
		parser->geometry_index += 1;
	}
	else
		return (INVALID_TYPE);
	return (OK);
}
