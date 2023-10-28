/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:42:10 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 04:01:03 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "projection_bonus.h"

static t_err	lex_checker(t_parser_obj *obj);
static void		cast_fields(t_parser_obj *obj);
static t_err	validate_fields(t_parser_obj *obj);
static void		apply_transforms(t_cone *cone);

int	parse_cone(t_parser_obj *obj)
{
	t_cone	*cone;

	cone = ft_calloc(1, sizeof(t_cone));
	obj->obj = cone;
	cone->type = CONE;
	obj->parser->geometry_count += 1;
	obj->status = OK;
	if (lex_checker(obj) != OK)
		return (1);
	cast_fields(obj);
	if (validate_fields(obj) != OK)
		return (1);
	apply_transforms(cone);
	print_msg("Parsing", "Parsed cone", TXT_COLOR_CYAN);
	return (0);
}

static t_err	lex_checker(t_parser_obj *obj)
{
	if (obj->fields_count != CYLINDER_FIELDS_COUNT)
		obj->status = INVALID_ARG_COUNT;
	else if (!is_str_vec3(obj->fields[1]) || !is_str_vec3(obj->fields[2])
		|| !is_str_vec3(obj->fields[5]))
		obj->status = INVALID_VEC3;
	else if (!ft_str_isdouble(obj->fields[3]))
		obj->status = INVALID_DIAMETER;
	else if (!ft_str_isdouble(obj->fields[4]))
		obj->status = INVALID_HEIGHT;
	return (obj->status);
}

static void	cast_fields(t_parser_obj *obj)
{
	t_cone	*cone;
	t_err	err;

	cone = (t_cone *) obj->obj;
	err = str_to_vec3(obj->fields[1], &cone->pos);
	err |= str_to_vec3(obj->fields[2], &cone->dir);
	cone->diameter = ft_atod(obj->fields[3]);
	cone->height = ft_atod(obj->fields[4]);
	err |= str_to_vec3(obj->fields[5], &cone->material.color);
	if (err != OK)
		obj->status = INVALID_VEC3;
}

static t_err	validate_fields(t_parser_obj *obj)
{
	t_cone	*cone;

	cone = (t_cone *) obj->obj;
	if (!is_valid_direction(&cone->dir))
		obj->status = INVALID_DIRECTION;
	else if (cone->diameter <= 0)
		obj->status = INVALID_DIAMETER;
	else if (cone->height <= 0)
		obj->status = INVALID_HEIGHT;
	else if (!is_valid_color(&cone->material.color))
		obj->status = INVALID_COLOR;
	return (obj->status);
}

static void	apply_transforms(t_cone *cone)
{
	t_matrix_op	ops[4];
	t_vec3		scale_v;
	double		radius;

	radius = cone->diameter / 2.0;
	set_vec3(radius, 1.0, radius, &scale_v);
	cone->transform = matrix_new_identity(4);
	ops[0] = (t_matrix_op){.op = SCALE, .params = scale_v};
	ops[1] = (t_matrix_op){.op = ROTATE_VEC, .params = cone->dir};
	ops[2] = (t_matrix_op){.op = TRANSLATE, .params = cone->pos};
	ops[3] = (t_matrix_op){.op = NOP};
	cone->transform = matrix_apply(cone->transform, ops);
	cone->inv_transform = matrix_inverse(cone->transform);
	cone->t_inv_transform = matrix_transpose(cone->inv_transform);
	cone->minimum = -cone->height / 2.0;
	cone->maximum = cone->height / 2.0;
	cone->is_closed = TRUE;
	cone->intersects = (t_isect_func) cone_intersect;
	cone->normal_at = cone_normal_at;
	divide(&cone->material.color, 255.0, &cone->material.color);
	cone->material.diffuse = DIFFUSE;
	cone->material.specular = SPECULAR;
	cone->material.ambient = AMBIENT;
	cone->material.shininess = SHININESS;
}
