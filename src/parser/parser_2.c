/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:04:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/22 18:21:47 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	*iter_print_errors(void *content, size_t, int, int);
static void	*add_obj_to_scene(void *content, size_t, int, int);

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

void	print_parser_errors(t_scene_parser *parser)
{
	ft_lst_func_apply(&parser->objs, iter_print_errors);
}

static void	*iter_print_errors(void *content, size_t, int, int)
{
	t_parser_obj	*obj;

	obj = (t_parser_obj *) content;
	if (obj->status != OK)
		print_error("Parsing", obj->status, obj->line);
	return (content);
}

void	populate_scene(t_scene_parser *parser)
{
	parser->scene = malloc(sizeof(t_scene));
	parser->scene->geometries = malloc(sizeof(t_geom_obj));
	parser->scene->lights = malloc(sizeof(t_point_light));
	ft_lst_func_apply(&parser->objs, add_obj_to_scene);
}

static void	*add_obj_to_scene(void *content, size_t, int, int)
{
	t_scene_parser	*parser;
	t_parser_obj	*obj;
	t_scene			*scene;

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
	else if (obj->type == SPHERE || obj->type == CYLINDER ||
			obj->type == PLANE)
	{
		scene->geometries[parser->geometry_index] = *((t_geom_obj *) obj->obj);
		parser->geometry_index += 1;
	}
	return (content);
}
