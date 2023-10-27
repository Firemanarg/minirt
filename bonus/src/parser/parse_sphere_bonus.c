/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:48 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 13:21:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "projection_bonus.h"

static t_err	lex_checker(t_parser_obj *obj);
static void		cast_fields(t_parser_obj *obj);
static t_err	validate_fields(t_parser_obj *obj);
static void		apply_transforms(t_sphere *sphere);

int	parse_sphere(t_parser_obj *obj)
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	obj->obj = sphere;
	sphere->type = SPHERE;
	obj->parser->geometry_count += 1;
	obj->status = OK;
	if (lex_checker(obj) != OK)
		return (1);
	cast_fields(obj);
	if (validate_fields(obj) != OK)
		return (1);
	apply_transforms(sphere);
	print_msg("Parsing", "Parsed sphere", TXT_COLOR_CYAN);
	return (0);
}

static t_err	lex_checker(t_parser_obj *obj)
{
	if (obj->fields_count != SPHERE_FIELDS_COUNT)
		obj->status = INVALID_ARG_COUNT;
	else if (!is_str_vec3(obj->fields[1]) || !is_str_vec3(obj->fields[3]))
		obj->status = INVALID_VEC3;
	else if (!ft_str_isdouble(obj->fields[2]))
		obj->status = INVALID_DIAMETER;
	return (obj->status);
}

static void	cast_fields(t_parser_obj *obj)
{
	t_sphere	*sphere;
	t_err		err;

	sphere = (t_sphere *) obj->obj;
	err = str_to_vec3(obj->fields[1], &sphere->pos);
	sphere->diameter = ft_atod(obj->fields[2]);
	err |= str_to_vec3(obj->fields[3], &sphere->material.color);
	if (err != OK)
		obj->status = INVALID_VEC3;
}

static t_err	validate_fields(t_parser_obj *obj)
{
	t_sphere	*sphere;

	sphere = (t_sphere *) obj->obj;
	if (!is_valid_color(&sphere->material.color))
		obj->status = INVALID_COLOR;
	else if (sphere->diameter <= 0)
		obj->status = INVALID_DIAMETER;
	return (obj->status);
}

static void	apply_transforms(t_sphere *sphere)
{
	t_matrix_op	ops[3];
	t_vec3		scale_v;
	double		radius;

	radius = sphere->diameter / 2.0;
	set_vec3(radius, radius, radius, &scale_v);
	sphere->transform = matrix_new_identity(4);
	ops[0] = (t_matrix_op){.op = SCALE, .params = scale_v};
	ops[1] = (t_matrix_op){.op = TRANSLATE, .params = sphere->pos};
	ops[2] = (t_matrix_op){.op = NOP};
	sphere->transform = matrix_apply(sphere->transform, ops);
	sphere->inv_transform = matrix_inverse(sphere->transform);
	sphere->t_inv_transform = matrix_transpose(sphere->inv_transform);
	sphere->material.color.r = sphere->material.color.r / 255.0;
	sphere->material.color.g = sphere->material.color.g / 255.0;
	sphere->material.color.b = sphere->material.color.b / 255.0;
	sphere->intersects = (t_isect_func)sphere_intersect;
	sphere->normal_at = sphere_normal_at;
	sphere->material.diffuse = DIFFUSE;
	sphere->material.specular = SPECULAR;
	sphere->material.ambient = AMBIENT;
	sphere->material.shininess = SHININESS;
}
