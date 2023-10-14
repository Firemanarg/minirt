/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:42:21 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/02 13:42:21 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_valid(t_plane *plane);
static void	apply_transforms(t_plane *plane);

t_plane	*parse_plane(char **fields, int fields_count)
{
	t_plane	*plane;
	t_err	err;

	if (fields_count != PLANE_FIELDS_COUNT)
		return (NULL);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->type = PLANE;
	err = str_to_vec3(fields[1], &plane->pos);
	err |= str_to_vec3(fields[2], &plane->dir);
	err |= str_to_vec3(fields[3], &(plane->material.color));
	if (err != OK || !is_valid(plane))
	{
		free(plane);
		return (NULL);
	}
	apply_transforms(plane);
	return (plane);
}

static int	is_valid(t_plane *plane)
{
	if (!is_valid_direction(&plane->dir))
		return (0);
	else if (!is_valid_color(&(plane->material.color)))
		return (0);
	return (1);
}

static void	apply_transforms(t_plane *plane)
{
	t_matrix_op	ops[5];

	plane->transform = matrix_new_identity(4);
	ops[0] = (t_matrix_op){.op = TRANSLATE, .params = plane->pos};
	ops[1] = (t_matrix_op){.op = ROTATE_X, .param = plane->dir.x};
	ops[2] = (t_matrix_op){.op = ROTATE_Y, .param = plane->dir.y};
	ops[3] = (t_matrix_op){.op = ROTATE_Z, .param = plane->dir.z};
	ops[4] = (t_matrix_op){.op = NOP};
	plane->transform = matrix_apply(plane->transform, ops);
	plane->inv_transform = matrix_inverse(plane->transform);
	plane->t_inv_transform = matrix_transpose(plane->inv_transform);
}
