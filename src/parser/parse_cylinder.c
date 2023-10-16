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

static int	is_valid(t_cylinder *cylinder);
static void	apply_cylinder_transforms(t_cylinder *cylinder);

static void	set_cylinder_pars(t_cylinder *cylinder)
{
	cylinder->minimum = -cylinder->height / 2.0;
	cylinder->maximum = cylinder->height / 2.0;
	cylinder->is_closed = TRUE;
	cylinder->intersects = (t_isect_func)cylinder_intersect;
	cylinder->normal_at = cylinder_normal_at;
	cylinder->map_uv = NULL;
	cylinder->material.color.r /= 255.0;
	cylinder->material.color.g /= 255.0;
	cylinder->material.color.b /= 255.0;
	cylinder->material.diffuse = DIFFUSE;
	cylinder->material.specular = SPECULAR;
	cylinder->material.ambient = AMBIENT;
}

t_err	parse_cylinder(char **fields, int fields_count, t_cylinder *cylinder)
{
	t_err	err;

	if (fields_count != CYLINDER_FIELDS_COUNT)
		return (INVALID_ARG);
	if (cylinder == NULL)
		return (INVALID_ARG);
	cylinder->type = CYLINDER;
	err = str_to_vec3(fields[1], &cylinder->pos);
	err |= str_to_vec3(fields[2], &cylinder->dir);
	cylinder->diameter = ft_atod(fields[3]);
	cylinder->height = ft_atod(fields[4]);
	err |= str_to_vec3(fields[5], &(cylinder->material.color));
	err |= !is_valid(cylinder);
	if (err != OK)
		return (INVALID_ARG);
	apply_cylinder_transforms(cylinder);
	cylinder->inv_transform = matrix_inverse(cylinder->transform);
	cylinder->t_inv_transform = matrix_transpose(cylinder->inv_transform);
	set_cylinder_pars(cylinder);
	return (OK);
}

static int	is_valid(t_cylinder *cylinder)
{
	if (!is_valid_direction(&cylinder->dir))
		return (0);
	else if (!is_valid_color(&(cylinder->material.color)))
		return (0);
	else if (cylinder->diameter <= 0)
		return (0);
	else if (cylinder->height <= 0)
		return (0);
	return (1);
}

static void	apply_cylinder_transforms(t_cylinder *cylinder)
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
}
