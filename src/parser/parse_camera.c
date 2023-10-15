/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:22 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/02 13:41:22 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_valid(t_camera *camera);
static void	apply_transforms(t_camera *camera);

t_err	parse_camera(char **fields, int fields_count, t_camera *camera)
{
	t_err	err;

	if (fields_count != CAMERA_FIELDS_COUNT)
		return (INVALID_ARG);
	if (camera == NULL)
		return (INVALID_ARG);
	camera->type = CAMERA;
	err = str_to_vec3(fields[1], &camera->pos);
	err |= str_to_vec3(fields[2], &camera->dir);
	camera->fov = ft_atoi(fields[3]);
	err |= !is_valid(camera);
	if (err != OK)
		return (INVALID_ARG);
	apply_transforms(camera);
	return (OK);
}

static int	is_valid(t_camera *camera)
{
	if (!is_valid_direction(&camera->dir))
		return (0);
	else if (!is_valid_fov(camera->fov))
		return (0);
	return (1);
}

static void	apply_transforms(t_camera *camera)
{
	t_matrix_op	ops[5];

	camera->transform = matrix_new_identity(4);
	ops[0] = (t_matrix_op){.op = TRANSLATE, .params = camera->pos};
	ops[1] = (t_matrix_op){.op = ROTATE_X, .param = camera->dir.x};
	ops[2] = (t_matrix_op){.op = ROTATE_Y, .param = camera->dir.y};
	ops[3] = (t_matrix_op){.op = ROTATE_Z, .param = camera->dir.z};
	ops[4] = (t_matrix_op){.op = NOP};
	camera->transform = matrix_apply(camera->transform, ops);
	camera->inv_transform = matrix_inverse(camera->transform);
	camera->t_inv_transform = matrix_transpose(camera->inv_transform);
}
