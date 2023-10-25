/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:04:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/25 15:56:48 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	*iter_print_errors(void *content, size_t i, int f, int l);
static void	*add_obj_to_scene(void *content, size_t i, int f, int l);

void	assign_parser_to_objs(t_scene_parser *parser)
{
	t_ftnode		*node;
	t_parser_obj	*obj;

	node = parser->objs.front;
	while (node != NULL)
	{
		obj = (t_parser_obj *) node->content;
		obj->parser = parser;
		node = node->next;
	}
}

/**
 * @brief Prints all errors found during parsing and returns 1 if any error was
 * found, 0 otherwise.
 *
 * @param parser The parser object containing the list of objects to be checked.
 *
 * @return int 1 if any error was found, 0 otherwise.
*/
int	print_parser_errors(t_scene_parser *parser)
{
	ft_lst_func_apply(&parser->objs, iter_print_errors);
	return (parser->err_flag);
}

static void	*iter_print_errors(void *content, size_t i, int f, int l)
{
	t_parser_obj	*obj;

	(void) (i && f && l);
	obj = (t_parser_obj *) content;
	if (obj->status != OK)
	{
		obj->parser->err_flag = 1;
		print_error("Parsing", obj->status, obj->line);
	}
	return (content);
}

void	populate_scene(t_scene_parser *parser)
{
	parser->scene = malloc(sizeof(t_scene));
	parser->scene->geometries = ft_calloc(
			parser->geometry_count + 1, sizeof(t_geom_obj));
	parser->scene->lights = ft_calloc(
			parser->light_count + 1, sizeof(t_point_light));
	ft_lst_func_apply(&parser->objs, add_obj_to_scene);
	parser->scene->geometries[parser->geometry_count] = (t_geom_obj){0};
	parser->scene->lights[parser->light_count] = (t_point_light){0};
}

static void	*add_obj_to_scene(void *content, size_t i, int f, int l)
{
	t_scene_parser	*parser;
	t_parser_obj	*obj;
	t_scene			*scene;

	(void) (i && f && l);
	obj = (t_parser_obj *) content;
	parser = obj->parser;
	scene = parser->scene;
	if (obj->type == CAMERA)
		scene->camera = *((t_camera *) obj->obj);
	else if (obj->type == AMBIENT_LIGHT)
		scene->ambient_light = *((t_ambient_light *) obj->obj);
	else if (obj->type == LIGHT)
	{
		scene->lights[parser->light_index] = *((t_point_light *) obj->obj);
		parser->light_index += 1;
	}
	else if (obj->type == SPHERE || obj->type == CYLINDER
		|| obj->type == PLANE)
	{
		scene->geometries[parser->geometry_index] = *((t_geom_obj *) obj->obj);
		parser->geometry_index += 1;
	}
	return (content);
}
