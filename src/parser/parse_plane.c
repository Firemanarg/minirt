/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:42:21 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 03:36:44 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "projection.h"

static t_err	lex_checker(t_parser_obj *obj);
static void		cast_fields(t_parser_obj *obj);
static t_err	validate_fields(t_parser_obj *obj);
static void		apply_transforms(t_plane *plane);

int	parse_plane(t_parser_obj *obj)
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	obj->obj = plane;
	plane->type = PLANE;
	obj->parser->geometry_count += 1;
	obj->status = OK;
	if (lex_checker(obj) != OK)
		return (1);
	cast_fields(obj);
	if (validate_fields(obj) != OK)
		return (1);
	apply_transforms(plane);
	print_msg("Parsing", "Parsed plane", TXT_COLOR_CYAN);
	return (0);
}

static t_err	lex_checker(t_parser_obj *obj)
{
	if (obj->fields_count != PLANE_FIELDS_COUNT)
		obj->status = INVALID_ARG_COUNT;
	else if (!is_str_vec3(obj->fields[1]) || !is_str_vec3(obj->fields[2])
		|| !is_str_vec3(obj->fields[3]))
		obj->status = INVALID_VEC3;
	return (obj->status);
}

static void	cast_fields(t_parser_obj *obj)
{
	t_plane	*plane;
	t_err	err;

	plane = (t_plane *) obj->obj;
	err = str_to_vec3(obj->fields[1], &plane->pos);
	err |= str_to_vec3(obj->fields[2], &plane->dir);
	err |= str_to_vec3(obj->fields[3], &plane->material.color);
	if (err != OK)
		obj->status = INVALID_VEC3;
}

static t_err	validate_fields(t_parser_obj *obj)
{
	t_plane	*plane;

	plane = (t_plane *) obj->obj;
	if (!is_valid_direction(&plane->dir))
		obj->status = INVALID_DIRECTION;
	else if (!is_valid_color(&plane->material.color))
		obj->status = INVALID_COLOR;
	return (obj->status);
}

static void	apply_transforms(t_plane *plane)
{
	t_matrix_op	ops[3];

	plane->transform = matrix_new_identity(4);
	ops[0] = (t_matrix_op){.op = ROTATE_VEC, .params = plane->dir};
	ops[1] = (t_matrix_op){.op = TRANSLATE, .params = plane->pos};
	ops[2] = (t_matrix_op){.op = NOP};
	plane->transform = matrix_apply(plane->transform, ops);
	plane->inv_transform = matrix_inverse(plane->transform);
	plane->t_inv_transform = matrix_transpose(plane->inv_transform);
	plane->intersects = (t_isect_func)plane_intersect;
	plane->normal_at = plane_normal_at;
	divide(&plane->material.color, 255.0, &plane->material.color);
	plane->material.diffuse = DIFFUSE;
	plane->material.ambient = AMBIENT;
}
