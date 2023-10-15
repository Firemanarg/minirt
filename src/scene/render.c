/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:33:27 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 15:07:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shading.h"
#include "graphics.h"

void	get_transformed_ray_origin(t_camera *camera, t_ray *ray)
{
	t_vec3	zero;

	zero.x = 0.0;
	zero.y = 0.0;
	zero.z = 0.0;
	matrix_point_multiply(camera->inv_transform, &zero, &ray->start);
}

void	ray_for_pixel(t_camera *camera, int p_x, int p_y, t_ray *ray)
{
	t_vec3	world;
	t_vec3	pixel;

	world.x = camera->half_width - (p_x + 0.5) * camera->pixel_size;
	world.y = camera->half_height - (p_y + 0.5) * camera->pixel_size;
	world.z = -1;
	matrix_point_multiply(camera->inv_transform, &world, &pixel);
	subtract(&pixel, &ray->start, &ray->direction);
	normalize(&ray->direction, &ray->direction);
}

t_err	render_image(t_camera *camera, t_scene *world, t_mlx_data *mlx_data)
{
	int			x;
	int			y;
	t_color		color;
	t_ray		ray;
	t_varray	*xs;

	xs = new_array(INITIAL_ARRAY_SIZE);
	if (!xs)
		return (ERR_ALLOC);
	get_transformed_ray_origin(camera, &ray);
	y = 0;
	while (y < camera->vsize)
	{
		x = 0;
		while (x < camera->hsize)
		{
			ray_for_pixel(camera, x, y, &ray);
			color_at(world, &ray, xs, &color);
			ft_pixel_put(mlx_data, x, y, &color);
			++x;
		}
		++y;
	}
	free_array(xs);
	return (OK);
}
