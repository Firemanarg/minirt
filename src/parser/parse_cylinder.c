/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:42:10 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 21:19:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "projection.h"

static t_err	lex_checker(t_parser_obj *obj);
static void		cast_fields(t_parser_obj *obj);
static t_err	validate_fields(t_parser_obj *obj);
static void		apply_transforms(t_cylinder *cylinder);

int	parse_cylinder(t_parser_obj *obj)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	obj->obj = cylinder;
	cylinder->type = CYLINDER;
	obj->parser->geometry_count += 1;
	obj->status = OK;
	if (lex_checker(obj) != OK)
		return (1);
	cast_fields(obj);
	if (validate_fields(obj) != OK)
		return (1);
	apply_transforms(cylinder);
	print_msg("Parsing", "Parsed cylinder", TXT_COLOR_CYAN);
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
	t_cylinder	*cylinder;
	t_err		err;

	cylinder = (t_cylinder *) obj->obj;
	err = str_to_vec3(obj->fields[1], &cylinder->pos);
	err |= str_to_vec3(obj->fields[2], &cylinder->dir);
	cylinder->diameter = ft_atod(obj->fields[3]);
	cylinder->height = ft_atod(obj->fields[4]);
	err |= str_to_vec3(obj->fields[5], &cylinder->material.color);
	if (err != OK)
		obj->status = INVALID_VEC3;
}

static t_err	validate_fields(t_parser_obj *obj)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *) obj->obj;
	if (!is_valid_direction(&cylinder->dir))
		obj->status = INVALID_DIRECTION;
	else if (cylinder->diameter <= 0)
		obj->status = INVALID_DIAMETER;
	else if (cylinder->height <= 0)
		obj->status = INVALID_HEIGHT;
	else if (!is_valid_color(&cylinder->material.color))
		obj->status = INVALID_COLOR;
	return (obj->status);
}

static void	apply_transforms(t_cylinder *cylinder)
{
	t_matrix_op	ops[4];
	t_vec3		scale_v;
	double		radius;

	radius = cylinder->diameter / 2.0;
	set_vec3(radius, 1.0, radius, &scale_v);
	cylinder->transform = matrix_new_identity(4);
	ops[0] = (t_matrix_op){.op = SCALE, .params = scale_v};
	ops[1] = (t_matrix_op){.op = ROTATE_VEC, .params = cylinder->dir};
	ops[2] = (t_matrix_op){.op = TRANSLATE, .params = cylinder->pos};
	ops[3] = (t_matrix_op){.op = NOP};
	cylinder->transform = matrix_apply(cylinder->transform, ops);
	cylinder->inv_transform = matrix_inverse(cylinder->transform);
	cylinder->t_inv_transform = matrix_transpose(cylinder->inv_transform);
	cylinder->minimum = -cylinder->height / 2.0;
	cylinder->maximum = cylinder->height / 2.0;
	cylinder->is_closed = TRUE;
	cylinder->intersects = (t_isect_func) cylinder_intersect;
	cylinder->normal_at = cylinder_normal_at;
	cylinder->map_uv = NULL;
	divide(&cylinder->material.color, 255.0, &cylinder->material.color);
	cylinder->material.diffuse = DIFFUSE;
	cylinder->material.specular = SPECULAR;
	cylinder->material.ambient = AMBIENT;
}
