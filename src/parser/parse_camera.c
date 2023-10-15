/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:22 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 17:53:28 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "graphics.h"
#include "shading.h"

static int	is_valid(t_camera *camera);
// static void	apply_transforms(t_camera *camera);

static void	set_camera_pars(int hsize, int vsize, double fov, t_camera *camera)
{
	double	half_view;
	double	aspect;

	camera->hsize = hsize;
	camera->vsize = vsize;
	fov *= (M_PI / 180);
	camera->fov = fov;
	half_view = tan(fov / 2.0);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1.0)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = camera->half_width * 2.0 / camera->hsize;
}

t_err	parse_camera(char **fields, int fields_count, t_camera *camera)
{
	t_err	err;
	t_vec3	up;
	t_vec3	to;

	up = (t_vec3){.x = 0.0, .y = 1.0, .z = 0.0};
	if (fields_count != CAMERA_FIELDS_COUNT)
		return (INVALID_ARG);
	if (camera == NULL)
		return (INVALID_ARG);
	camera->type = CAMERA;
	err = str_to_vec3(fields[1], &camera->pos);
	err |= str_to_vec3(fields[2], &camera->dir);
	add(&camera->pos, &camera->dir, &to);
	camera->fov = ft_atoi(fields[3]);
	err |= !is_valid(camera);
	if (err != OK)
		return (INVALID_ARG);
	camera->transform = view_transform(&camera->pos, &to, &up);
	camera->inv_transform = matrix_inverse(camera->transform);
	camera->t_inv_transform = NULL;
	// apply_transforms(camera);
	set_camera_pars(WINDOW_WIDTH, WINDOW_HEIGHT, camera->fov, camera);
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

// static void	apply_transforms(t_camera *camera)
// {
// 	t_matrix_op	ops[5];

// 	camera->transform = matrix_new_identity(4);
// 	ops[0] = (t_matrix_op){.op = TRANSLATE, .params = camera->pos};
// 	ops[1] = (t_matrix_op){.op = ROTATE_X, .param = camera->dir.x};
// 	ops[2] = (t_matrix_op){.op = ROTATE_Y, .param = camera->dir.y};
// 	ops[3] = (t_matrix_op){.op = ROTATE_Z, .param = camera->dir.z};
// 	ops[4] = (t_matrix_op){.op = NOP};
// 	camera->transform = matrix_apply(camera->transform, ops);
// 	camera->inv_transform = matrix_inverse(camera->transform);
// 	camera->t_inv_transform = matrix_transpose(camera->inv_transform);
// }
