/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:42:10 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/02 13:42:10 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_valid(t_cylinder *cylinder);
static void	apply_transforms(t_cylinder *cylinder);

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
	apply_transforms(cylinder);
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

static void	apply_transforms(t_cylinder *cylinder)
{
	t_matrix_op	ops[5];

	cylinder->transform = matrix_new_identity(4);
	ops[0] = (t_matrix_op){.op = TRANSLATE, .params = cylinder->pos};
	ops[1] = (t_matrix_op){.op = ROTATE_X, .param = cylinder->dir.x};
	ops[2] = (t_matrix_op){.op = ROTATE_Y, .param = cylinder->dir.y};
	ops[3] = (t_matrix_op){.op = ROTATE_Z, .param = cylinder->dir.z};
	ops[4] = (t_matrix_op){.op = NOP};
	cylinder->transform = matrix_apply(cylinder->transform, ops);
}
