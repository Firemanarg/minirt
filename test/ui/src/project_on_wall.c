/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_on_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:15:20 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/05 02:28:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ui.h>

static void	get_default_material(t_material *material)
{
	set_material_color(material, 1.0, 0.2, 1.0);
	set_material_coefficients(material, 0.1, 0.9, 0.9);
	set_material_shininess(material, 200.0);
}

void	init_trace_args(int canvas_pixels, double wall_size, double z,
			t_trace_args *t)
{
	t->wall_z = z;
	t->wall_size = wall_size;
	t->pixel_size = wall_size / canvas_pixels;
	t->canvas_pixels = canvas_pixels;
	set_vec3(0.0, 0.0, -5.0, &t->ray_origin);
}

void	trace_pixel(t_args *args, t_trace_args *t, int x, int y)
{
	if (hit(t->intersections))
	{
		ft_pixel_put(&args->mlx_data, x, y,
			convert_color(&(t->obj.material.color)));
	}
	else
		ft_pixel_put(&args->mlx_data, x, y, 0);
}

void	get_ray_direction(t_trace_args *t, t_vec3 *position, t_ray *ray)
{
	t_vec3	direction;
	t_vec3	normalized_direction;

	subtract(position, &t->ray_origin, &direction);
	normalize(&direction, &normalized_direction);
	set_ray(&t->ray_origin, &normalized_direction, ray);
}

void	get_ray(t_trace_args *trace_args, int x, int y)
{
	double	world_x;
	double	world_y;
	double	half_wall_size;
	t_vec3	position;

	half_wall_size = trace_args->wall_size / 2;
	world_x = half_wall_size - trace_args->pixel_size * x;
	world_y = half_wall_size - trace_args->pixel_size * y;
	set_vec3(world_x, world_y, trace_args->wall_z, &position);
	get_ray_direction(trace_args, &position, &trace_args->ray);
}

void	trace_all(t_args *args, t_trace_args *trace_args)
{
	t_material	material;
	int			x;
	int			y;

	trace_args->intersections = new_array(2);
	get_default_material(&material);
	set_sphere(&trace_args->obj, matrix_new_identity(4), &material);
	y = 0;
	while (y < trace_args->canvas_pixels - 1)
	{
		x = 0;
		while (x < trace_args->canvas_pixels - 1)
		{
			get_ray(trace_args, x++, y);
			reset_array(trace_args->intersections);
			trace_args->obj.intersects(&trace_args->obj, &trace_args->ray,
				trace_args->intersections);
			trace_pixel(args, trace_args, x, y);
			// mlx_put_image_to_window(args->mlx, args->mlx_win,
			// 	args->mlx_data.img, 0, 0);
		}
		++y;
	}
}

int	create_projection_window(t_args *args, t_trace_args *trace_args)
{
	const int	window_size = 400;

	init_args(args, window_size, window_size);
	init_trace_args(window_size, 7, 10, trace_args);
	trace_all(args, trace_args);
	mlx_put_image_to_window(args->mlx, args->mlx_win,
				args->mlx_data.img, 0, 0);
	matrix_free(trace_args->obj.transform);
	matrix_free(trace_args->obj.inv_transform);
	free_array(trace_args->intersections);
	mlx_hook(args->mlx_win, ON_DESTROY,
		MASK_STRUCTURE_NOTIFY, on_destroy, args);
	mlx_hook(args->mlx_win, ON_KEYDOWN, MASK_KEY_PRESS, on_key_press, args);
	mlx_loop(args->mlx);
	return (0);
}

int	main(void)
{
	t_args			args;
	t_trace_args	trace_args;

	create_projection_window(&args, &trace_args);
	return (0);
}
