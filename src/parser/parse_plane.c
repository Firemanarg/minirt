/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:42:21 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 10:21:28 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "projection.h"

static int	is_valid(t_plane *plane);
// static void	apply_transforms(t_plane *plane);

static void	set_plane_pars(t_plane *plane)
{
	plane->intersects = (t_isect_func)plane_intersect;
	plane->normal_at = plane_normal_at;
	plane->map_uv = NULL;
	plane->material.color.r /= 255.0;
	plane->material.color.g /= 255.0;
	plane->material.color.b /= 255.0;
	plane->material.diffuse = DIFFUSE;
	plane->material.specular = SPECULAR;
	plane->material.ambient = AMBIENT;
}

t_err	parse_plane(char **fields, int fields_count, t_plane *plane)
{
	t_err	err;
	t_vec3	axis;

	axis = (t_vec3){.x = 0, .y = 1, .z = 0};
	if (fields_count != PLANE_FIELDS_COUNT)
		return (INVALID_ARG);
	if (!plane)
		return (INVALID_ARG);
	plane->type = PLANE;
	err = str_to_vec3(fields[1], &plane->pos);
	err |= str_to_vec3(fields[2], &plane->dir);
	err |= str_to_vec3(fields[3], &(plane->material.color));
	err |= !is_valid(plane);
	if (err != OK)
		return (INVALID_ARG);
	// apply_transforms(plane);
	plane->transform = matrix_rotate_translate(
			&axis, &plane->dir, &plane->pos);
	plane->inv_transform = matrix_inverse(plane->transform);
	plane->t_inv_transform = matrix_transpose(plane->inv_transform);
	set_plane_pars(plane);
	return (OK);
}

static int	is_valid(t_plane *plane)
{
	if (!is_valid_direction(&plane->dir))
		return (0);
	else if (!is_valid_color(&(plane->material.color)))
		return (0);
	return (1);
}

// static void	apply_transforms(t_plane *plane)
// {
// 	t_matrix_op	ops[5];

// 	plane->transform = matrix_new_identity(4);
// 	ops[0] = (t_matrix_op){.op = ROTATE_X, .param = plane->dir.x};
// 	ops[1] = (t_matrix_op){.op = ROTATE_Y, .param = plane->dir.y};
// 	ops[2] = (t_matrix_op){.op = ROTATE_Z, .param = plane->dir.z};
// 	ops[3] = (t_matrix_op){.op = TRANSLATE, .params = plane->pos};
// 	ops[4] = (t_matrix_op){.op = NOP};
// 	plane->transform = matrix_apply(plane->transform, ops);
// 	plane->inv_transform = matrix_inverse(plane->transform);
// 	plane->t_inv_transform = matrix_transpose(plane->inv_transform);
// }
