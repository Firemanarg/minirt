/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:03:08 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/07 03:32:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "projection.h"

void	set_camera(int hsize, int vsize, double fov, t_camera *camera)
{
	double	half_view;
	double	aspect;

	camera->hsize = hsize;
	camera->vsize = vsize;
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
	camera->transform = NULL;
	camera->inv_transform = NULL;
}

t_err	set_camera_transform(t_matrix *transform, t_camera *camera)
{
	free_camera(camera);
	camera->transform = transform;
	if (camera->transform == NULL)
		return (ERR_ALLOC);
	camera->inv_transform = matrix_inverse(transform);
	if (camera->inv_transform == NULL)
		return (ERR_ALLOC);
	return (OK);
}

void	free_camera(t_camera *camera)
{
	matrix_free(camera->transform);
	matrix_free(camera->inv_transform);
	camera->transform = NULL;
	camera->inv_transform = NULL;
}
