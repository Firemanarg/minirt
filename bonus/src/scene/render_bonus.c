/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:33:27 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:48:03 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shading_bonus.h"

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

t_err	render_image(t_scene *world, t_mlx_data *mlx_data)
{
	t_render_args	args;

	args = (t_render_args){0};
	print_msg("Rendering", "Rendering image", TXT_COLOR_MAGENTA);
	args.xs = new_array(INITIAL_ARRAY_SIZE);
	if (!args.xs)
		return (ERR_ALLOC);
	get_transformed_ray_origin(&world->camera, &args.ray);
	print_progress(0, world->camera.vsize * world->camera.hsize, "Rendering");
	while (args.y < world->camera.vsize)
	{
		args.x = 0;
		while (args.x < world->camera.hsize)
		{
			ray_for_pixel(&world->camera, args.x, args.y, &args.ray);
			color_at(world, &args.ray, args.xs, &args.color);
			ft_pixel_put(mlx_data, args.x, args.y, &args.color);
			++(args.x);
		}
		print_progress(
				args.y * world->camera.hsize + (args.x + 1), 0, "Rendering");
		++(args.y);
	}
	free_array(args.xs);
	return (OK);
}
