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
static void	*get_parser_obj(void *line, size_t index, int f, int l);
static void	*parse_obj(void *content, size_t i, int f, int l);
static void	check_objs_count(t_scene_parser *parser);

t_scene	*parse_file(char *file_name)
{
	t_scene_parser	parser;

	parser = (t_scene_parser){0};
	parser.fd = open(file_name, O_RDONLY);
	if (parser.fd < 0)
		return (NULL);
	get_file_as_strlist(parser.fd, &parser.objs);
	close(parser.fd);
	ft_lst_func_apply(&parser.objs, get_parser_obj);
	ft_lst_rmv_null(&parser.objs);
	assign_parser_to_objs(&parser);
	if (print_parser_errors(&parser))
	{
		ft_lst_clear(&parser.objs, free_parser_obj);
		return (NULL);
	}
	ft_lst_func_apply(&parser.objs, parse_obj);
	check_objs_count(&parser);
	if (!print_parser_errors(&parser))
		populate_scene(&parser);
	ft_lst_clear(&parser.objs, free_parser_obj);
	return (parser.scene);
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

static void	*get_parser_obj(void *line, size_t index, int f, int l)
{
	t_parser_obj	*obj;

	(void) (f && l);
	if (line == NULL)
		return (NULL);
	obj = malloc(sizeof(t_parser_obj));
	*obj = (t_parser_obj){0};
	obj->fields = ft_split((char *) line, ' ');
	while (obj->fields[obj->fields_count] != NULL)
		obj->fields_count++;
	obj->type = get_type_by_str(obj->fields[0]);
	if (obj->type == UNKNOWN)
		obj->status = INVALID_TYPE;
	obj->line = index + 1;
	free(line);
	return (obj);
}

static void	*parse_obj(void *content, size_t i, int f, int l)
{
	t_parser_obj	*obj;
	int				*err_flag;

	(void) (i && f && l);
	obj = (t_parser_obj *) content;
	err_flag = &obj->parser->err_flag;
	if (obj == NULL)
		return (NULL);
	if (obj->type == AMBIENT_LIGHT)
		*err_flag |= parse_ambient_light(obj);
	else if (obj->type == CAMERA)
		*err_flag |= parse_camera(obj);
	else if (obj->type == LIGHT)
		*err_flag |= parse_light(obj);
	else if (obj->type == SPHERE)
		*err_flag |= parse_sphere(obj);
	else if (obj->type == CYLINDER)
		*err_flag |= parse_cylinder(obj);
	else if (obj->type == PLANE)
		*err_flag |= parse_plane(obj);
	return (content);
}

static void	check_objs_count(t_scene_parser *parser)
{
	if (parser->amb_light_count != 1)
	{
		if (parser->amb_light_count == 0)
			print_error("Parsing", MISSING_AMBIENT_LIGHT, 0);
		else if (parser->amb_light_count > 1)
			print_error("Parsing", TOO_MANY_AMBIENT_LIGHTS, 0);
		parser->err_flag = 1;
	}
	if (parser->camera_count != 1)
	{
		if (parser->camera_count == 0)
			print_error("Parsing", MISSING_CAMERA, 0);
		else if (parser->camera_count > 1)
			print_error("Parsing", TOO_MANY_CAMERAS, 0);
		parser->err_flag = 1;
	}
	if (parser->light_count < 1)
	{
		print_error("Parsing", MISSING_LIGHT, 0);
		parser->err_flag = 1;
	}
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
