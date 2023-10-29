/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:42 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/29 02:27:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

static void	get_file_as_strlist(int fd, t_ftlist *list);
static void	*get_parser_obj(void *line, size_t index, int f, int l);
static void	*parse_obj(void *content, size_t i, int f, int l);
static void	check_objs_count(t_scene_parser *parser);

t_scene	*parse_file(char *file_name)
{
	t_scene_parser	parser;

	ft_putstr_fd(TXT_COLOR_MAGENTA"[Parsing]: Parsing file <", 1);
	ft_putstr_fd(file_name, 1);
	ft_putstr_fd(">\n"TXT_COLOR_RESET, 1);
	parser = (t_scene_parser){0};
	parser.fd = open(file_name, O_RDONLY);
	if (parser.fd < 0)
		return (NULL);
	get_file_as_strlist(parser.fd, &parser.objs);
	close(parser.fd);
	ft_lst_func_apply(&parser.objs, get_parser_obj);
	ft_lst_rmv_null(&parser.objs);
	assign_parser_to_objs(&parser);
	ft_lst_func_apply(&parser.objs, parse_obj);
	check_objs_count(&parser);
	if (print_parser_errors(&parser))
	{
		ft_lst_clear(&parser.objs, free_parser_obj);
		return (NULL);
	}
	populate_scene(&parser);
	ft_lst_clear(&parser.objs, clean_parser_obj);
	return (parser.scene);
}

static void	get_file_as_strlist(int fd, t_ftlist *list)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, "\n");
		ft_lst_push_back(list, trimmed);
		free(line);
		line = get_next_line(fd);
	}
}

static void	*get_parser_obj(void *line, size_t index, int f, int l)
{
	t_parser_obj	*obj;

	(void) (f && l);
	if (line == NULL)
		return (NULL);
	obj = ft_calloc(1, sizeof(t_parser_obj));
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
	else if (obj->type == CONE)
		*err_flag |= parse_cone(obj);
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
