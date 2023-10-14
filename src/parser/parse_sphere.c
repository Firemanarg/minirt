/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:48 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/02 13:41:48 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_valid(t_sphere *sphere);
static void	apply_transforms(t_sphere *sphere);

t_sphere	*parse_sphere(char **fields, int fields_count)
{
	t_sphere	*sphere;
	t_err		err;

	if (fields_count != SPHERE_FIELDS_COUNT)
		return (NULL);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->type = SPHERE;
	err = str_to_vec3(fields[1], &sphere->pos);
	sphere->diameter = ft_atod(fields[2]);
	err |= str_to_vec3(fields[3], &(sphere->material.color));
	if (err != OK || !is_valid(sphere))
	{
		free(sphere);
		return (NULL);
	}
	apply_transforms(sphere);
	return (sphere);
}

static int	is_valid(t_sphere *sphere)
{
	if (!is_valid_color(&(sphere->material.color)))
		return (0);
	else if (sphere->diameter <= 0)
		return (0);
	return (1);
}

static void	apply_transforms(t_sphere *sphere)
{
	t_matrix_op	ops[5];

	sphere->transform = matrix_new_identity(4);
	ops[0] = (t_matrix_op){.op = TRANSLATE, .params = sphere->pos};
	ops[1] = (t_matrix_op){.op = ROTATE_X, .param = sphere->dir.x};
	ops[2] = (t_matrix_op){.op = ROTATE_Y, .param = sphere->dir.y};
	ops[3] = (t_matrix_op){.op = ROTATE_Z, .param = sphere->dir.z};
	ops[4] = (t_matrix_op){.op = NOP};
	sphere->transform = matrix_apply(sphere->transform, ops);
	sphere->inv_transform = matrix_inverse(sphere->transform);
	sphere->t_inv_transform = matrix_transpose(sphere->inv_transform);
}
