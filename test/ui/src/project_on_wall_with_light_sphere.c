/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_on_wall_with_light_sphere.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:15:20 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 19:58:44 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ui.h>

static void	get_default_material(t_material *material)
{
	set_material_color(material, 1.0, 0.2, 1.0);
	set_material_coefficients(material, 0.1, 0.9, 0.9);
	set_material_shininess(material, 200.0);
}

static void	get_point_light(t_point_light *light, t_vec3 *pos, t_color *color)
{
	light->intensity = *color;
	light->pos = *pos;
}

void	init_trace_args(int canvas_pixels, double wall_size, double z,
			t_trace_args *t)
{
	t->wall_z = z;
	t->wall_size = wall_size;
	t->pixel_size = wall_size / canvas_pixels;
	t->canvas_pixels = canvas_pixels;
	get_default_material(&t->phong.material);
	get_point_light(&t->phong.light, &(t_vec3){.x = -10, .y = 10, .z = -10},
		&(t_color){.r = 1.0, .g = 1.0, .b = 1.0});
	set_vec3(0.0, 0.0, -5.0, &t->ray_origin);
}

void	trace_pixel(t_args *args, t_trace_args *t, int x, int y)
{
	t_color	final_color;
	t_obj	*obj;
	t_isect	*hit_isect;

	hit_isect = hit(t->intersections);
	if (hit_isect)
	{
		obj = hit_isect->obj;
		position(&t->ray, hit_isect->t, &t->phong.point);
		obj_normal_at(obj, &t->phong.point, &t->phong.normal);
		set_vec3(0.0, 0.0, 0.0, &t->phong.eye);
		subtract(&t->phong.eye, &t->ray.direction, &t->phong.eye);
		lighting(&t->phong, &final_color);
		ft_pixel_put(&args->mlx_data, x, y, &final_color);
	}
	else
		ft_pixel_put(&args->mlx_data, x, y, 0);
}

void	get_ray_direction(t_trace_args *t, t_vec3 *position, t_ray *ray)
{
	t_vec3	direction;

	subtract(position, &t->ray_origin, &direction);
	normalize(&direction, &direction);
	set_ray(&t->ray_origin, &direction, ray);
}

void	get_ray(t_trace_args *t, int x, int y)
{
	double	world_x;
	double	world_y;
	double	half_wall_size;
	t_vec3	position;

	half_wall_size = t->wall_size / 2;
	world_x = -half_wall_size + t->pixel_size * x;
	world_y = half_wall_size - t->pixel_size * y;
	set_vec3(world_x, world_y, t->wall_z, &position);
	get_ray_direction(t, &position, &t->ray);
}

void	trace_all(t_args *args, t_trace_args *t)
{
	int			x;
	int			y;
	t_matrix	*id;
	t_matrix	*scale;

	t->intersections = new_array(2);
	id = matrix_new_identity(4);
	scale = matrix_scaling(&(t_vec3){.x = 1.0, .y = 0.3, .z = 1.0});
	set_sphere(&t->obj, matrix_multiply(scale, id), &t->phong.material);
	y = 0;
	while (y < t->canvas_pixels - 1)
	{
		x = 0;
		while (x < t->canvas_pixels - 1)
		{
			get_ray(t, x, y);
			reset_array(t->intersections);
			obj_intersect(&t->obj, &t->ray, t->intersections);
			trace_pixel(args, t, x, y);
			// mlx_put_image_to_window(args->mlx, args->mlx_win,
			//	args->mlx_data.img, 0, 0);
			++x;
		}
		++y;
	}
	matrix_free(id);
	matrix_free(scale);
}

int	create_projection_window(t_args *args, t_trace_args *trace_args)
{
	const int	window_size = 800;

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
