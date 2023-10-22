/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:42 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 06:52:17 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// ----------------------------- NEW PARSER ------------------------------------

static void	get_file_as_strlist(int fd, t_ftlist *list);
static void	*get_parser_obj(void *line, size_t index, int, int);
static void	free_parser_obj(void *obj);
static void	*parse_obj(void *content, size_t, int, int);
// static void	*print_fields(void *p_obj, size_t, int, int);

// PAREI AQUI: Falta inserir os objetos na cena após o parsing. Falta também
// recriar a função de parse para cada objeto utilizando a nova struct.

t_scene	*parse_file(char *file_name)
{
	t_scene		*scene;
	t_ftlist	objs;
	int			fd;

	(void) scene;
	objs = (t_ftlist){0};
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	get_file_as_strlist(fd, &objs);
	close(fd);
	ft_lst_func_apply(&objs, get_parser_obj);
	ft_lst_func_apply(&objs, parse_obj);
	ft_lst_clear(&objs, free_parser_obj);
	return (NULL);
}

static void	get_file_as_strlist(int fd, t_ftlist *list)
{
	char			buff[PARSER_BUFFER_SIZE + 1];
	t_line_parser	lp;

	ft_bzero(buff, PARSER_BUFFER_SIZE + 1);
	lp.aux = (char *) buff;
	while (read(fd, lp.aux, PARSER_BUFFER_SIZE - (lp.aux - (char *) buff)) > 0)
	{
		lp.iter = buff;
		lp.endl_ptr = ft_strchr(lp.iter, '\n');
		while (lp.endl_ptr != NULL)
		{
			lp.line = ft_strndup(lp.iter, lp.endl_ptr - lp.iter);
			ft_lst_push_back(list, lp.line);
			lp.iter = lp.endl_ptr + 1;
			lp.endl_ptr = ft_strchr(lp.iter, '\n');
		}
		lp.aux = ft_strrchr(lp.iter, '\0');
		ft_strlcpy(buff, lp.iter, lp.aux - lp.iter + 1);
	}
	if (buff[0] == '\0')
		return ;
	lp.line = ft_strdup(buff);
	ft_lst_push_back(list, lp.line);
}

static void	*get_parser_obj(void *line, size_t index, int, int)
{
	t_parser_obj	*obj;

	if (line == NULL)
		return (NULL);
	obj = malloc(sizeof(t_parser_obj));
	*obj = (t_parser_obj){0};
	obj->fields = ft_split((char *) line, ' ');
	while (obj->fields[obj->fields_count] != NULL)
		obj->fields_count++;
	obj->type = get_type_by_str(obj->fields[0]);
	obj->line = index + 1;
	free(line);
	return (obj);
}

static void	free_parser_obj(void *obj)
{
	t_parser_obj	*aux;

	aux = (t_parser_obj *) obj;
	if (aux == NULL)
		return ;
	ft_clear_arr((void **) aux->fields, NULL);
	free(aux);
}

static void	*parse_obj(void *content, size_t, int, int)
{
	t_parser_obj	*obj;

	obj = (t_parser_obj *) content;
	if (obj == NULL)
		return (NULL);
	if (obj->type == AMBIENT_LIGHT)
		parse_ambient_light(obj);
	// else if (obj->type == CAMERA)
	// 	parse_camera(obj);
	// else if (obj->type == LIGHT)
	// 	parse_light(obj);
	// else if (obj->type == SPHERE)
	// 	parse_sphere(obj);
	// else if (obj->type == CYLINDER)
	// 	parse_cylinder(obj);
	// else if (obj->type == PLANE)
	// 	parse_plane(obj);
	return (content);
}

// static void	*print_fields(void *p_obj, size_t, int, int)
// {
// 	t_parser_obj	*obj;
// 	char			**iter;

// 	obj = (t_parser_obj *) p_obj;
// 	if (obj == NULL)
// 		return (NULL);
// 	ft_printf("\ntype: %d\n", obj->type);
// 	ft_printf("fields_count: %d\n", obj->fields_count);
// 	ft_printf("fields: (");
// 	iter = obj->fields;
// 	while (*iter != NULL)
// 	{
// 		ft_printf("\"%s\"", *iter);
// 		iter++;
// 		if (*iter != NULL)
// 			ft_printf(", ");
// 	}
// 	ft_printf(")\n");
// 	return (p_obj);
// }

// ----------------------------- OLD PARSER ------------------------------------

// static t_err		parse_line(t_scene_parser *parser);
// static t_err		parse_obj(char **fields, int fields_count,
// 						t_scene_parser *parser);
// static int			iterate_and_close_parser_file(t_scene_parser *parser);
// static t_err		add_to_scene(t_scene_parser *parser);

// t_scene	*parse_file(char *file_name)
// {
// 	t_scene_parser	*args;
// 	t_scene			*scene;
// 	int				aux;

// 	args = get_scene_parser_args(file_name);
// 	if (args == NULL)
// 		return (NULL);
// 	if (args->scene == NULL)
// 	{
// 		free(args);
// 		return (NULL);
// 	}
// 	args->fd = open(file_name, O_RDONLY);
// 	aux = iterate_and_close_parser_file(args);
// 	scene = args->scene;
// 	free(args);
// 	if (aux != 1)
// 	{
// 		if (scene != NULL)
// 			free_scene(scene);
// 		return (NULL);
// 	}
// 	return (scene);
// }

// static t_err	parse_line(t_scene_parser *parser)
// {
// 	char		**fields;
// 	char		*endl_ptr;
// 	int			fields_count;
// 	t_err		err;

// 	endl_ptr = ft_strchr(parser->line, '\n');
// 	if (endl_ptr != NULL)
// 		*endl_ptr = '\0';
// 	if (parser->line[0] == '\0')
// 		return (OK);
// 	fields = ft_split(parser->line, ' ');
// 	if (fields == NULL)
// 		return (INVALID_ARG);
// 	fields_count = 0;
// 	while (fields[fields_count] != NULL)
// 		fields_count++;
// 	if (fields_count == 0)
// 	{
// 		free(fields);
// 		return (INVALID_ARG);
// 	}
// 	err = parse_obj(fields, fields_count, parser);
// 	ft_clear_arr((void **) fields, NULL);
// 	return (err);
// }

// static int	iterate_and_close_parser_file(t_scene_parser *parser)
// {
// 	t_err	err;

// 	if (parser == NULL || parser->fd < 0)
// 		return (0);
// 	parser->line = get_next_line(parser->fd);
// 	while (parser->line != NULL)
// 	{
// 		err = parse_line(parser);
// 		if (err != OK || parser->line[0] != '\0')
// 			err |= add_to_scene(parser);
// 		if (err != OK)
// 			break ;
// 		free(parser->line);
// 		parser->line = get_next_line(parser->fd);
// 	}
// 	close(parser->fd);
// 	parser->fd = -1;
// 	if (parser->line == NULL)
// 		return (1);
// 	free(parser->line);
// 	parser->line = NULL;
// 	return (0);
// }

// static t_err	parse_obj(char **fields, int fields_count,
// 		t_scene_parser *parser)
// {
// 	t_obj_type	type;

// 	parser->obj = (t_def_obj){0};
// 	type = get_type_by_str(fields[0]);
// 	if (type == AMBIENT_LIGHT)
// 		return (parse_ambient_light(fields, fields_count,
// 				(t_ambient_light *) &parser->obj));
// 	else if (type == CAMERA)
// 		return (parse_camera(fields, fields_count,
// 				(t_camera *) &parser->obj));
// 	else if (type == LIGHT)
// 		return (parse_light(fields, fields_count,
// 				(t_point_light *) &parser->obj));
// 	else if (type == SPHERE)
// 		return (parse_sphere(fields, fields_count,
// 				(t_sphere *) &parser->obj));
// 	else if (type == CYLINDER)
// 		return (parse_cylinder(fields, fields_count,
// 				(t_cylinder *) &parser->obj));
// 	else if (type == PLANE)
// 		return (parse_plane(fields, fields_count,
// 				(t_plane *) &parser->obj));
// 	return (INVALID_ARG);
// }

// static t_err	add_to_scene(t_scene_parser *parser)
// {
// 	t_obj_type	type;

// 	type = parser->obj.c.type;
// 	if (type == AMBIENT_LIGHT)
// 		parser->scene->ambient_light = *((t_ambient_light *) &parser->obj);
// 	else if (type == CAMERA)
// 		parser->scene->camera = *((t_camera *) &parser->obj);
// 	else if (type == LIGHT)
// 	{
// 		parser->scene->lights[parser->light_index] = (
// 				*((t_point_light *) &parser->obj));
// 		parser->light_index += 1;
// 	}
// 	else if (type == SPHERE || type == CYLINDER || type == PLANE)
// 	{
// 		parser->scene->geometries[parser->geometry_index] = (
// 				*((t_geom_obj *) &parser->obj));
// 		parser->geometry_index += 1;
// 	}
// 	else
// 		return (INVALID_TYPE);
// 	return (OK);
// }
