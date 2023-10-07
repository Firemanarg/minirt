/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:05:14 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 22:44:37 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_test.h"

static void	set_default_material(t_material *m)
{
	m->color = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->ambient = 0.1;
	m->shininess = 200.0;
}

static void	set_material(t_material *m)
{
	m->color = (t_color){.r = 0.8, .g = 1.0, .b = 0.6};
	m->diffuse = 0.7;
	m->specular = 0.2;
	m->ambient = 0.1;
	m->shininess = 200.0;
}

static void	set_default_world(t_scene *world)
{
	const t_matrix_op	ops[2] = {
	{.op = SCALE, .params = {.x = 0.5, .y = 0.5, .z = 0.5}}, {0}};
	t_material			m1;
	t_material			m2;

	world->lights = malloc(sizeof(*(world->lights)) * 1);
	world->geometries = malloc(sizeof(*(world->geometries)) * 3);
	set_material(&m1);
	set_sphere(world->geometries, matrix_new_identity(4), &m1);
	set_default_material(&m2);
	set_sphere(world->geometries + 1, matrix_apply(matrix_new_identity(4),
			(t_matrix_op *)ops), &m2);
	world->lights[0] = (t_point_light){
		.pos = (t_vec3){.x = -10, .y = 10, .z = -10},
		.intensity = (t_color){.r = 1, .g = 1, .b = 1}};
	world->geometries[2] = (t_geom_obj){0};
}

static unsigned int	pixel_at(t_mlx_data *mlx_data, int x, int y)
{
	return (*(unsigned int *)(mlx_data->addr
		+ (y * mlx_data->line_length + x * (mlx_data->bits_per_pixel / 8))));
}

Test(camera, create_camera)
{
	t_camera	camera;

	set_camera(160, 120, M_PI_2, &camera);
	set_camera_transform(matrix_new_identity(4), &camera);
	cr_expect(eq(int, camera.hsize, 160));
	cr_expect(eq(int, camera.vsize, 120));
	cr_expect(epsilon_eq(dbl, camera.fov, M_PI_2, EPSILON));

	cr_expect(epsilon_eq(dbl, camera.transform->data[0][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[0][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[0][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, camera.transform->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[1][1], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[1][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, camera.transform->data[2][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[2][2], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[2][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, camera.transform->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, camera.transform->data[3][3], 1.0, EPSILON));

	free_camera(&camera);
}

Test(camera, horizontal_canvas_pixel_size)
{
	t_camera	camera;

	set_camera(200, 125, M_PI_2, &camera);
	set_camera_transform(matrix_new_identity(4), &camera);
	cr_expect(epsilon_eq(dbl, camera.pixel_size, 0.01, EPSILON));
	free_camera(&camera);
}

Test(camera, vertical_canvas_pixel_size)
{
	t_camera camera;

	set_camera(125, 200, M_PI_2, &camera);
	set_camera_transform(matrix_new_identity(4), &camera);
	cr_expect(epsilon_eq(dbl, camera.pixel_size, 0.01, EPSILON));
	free_camera(&camera);
}

Test(camera, ray_through_canvas_center)
{
	t_camera	camera;
	t_ray		ray;

	set_camera(201, 101, M_PI_2, &camera);
	set_camera_transform(matrix_new_identity(4), &camera);
	ray_for_pixel(&camera, 100, 50, &ray);

	cr_expect(epsilon_eq(dbl, ray.start.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.start.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.start.z, 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, ray.direction.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.direction.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.direction.z, -1.0, EPSILON));

	free_camera(&camera);
}

Test(camera, ray_through_canvas_corner)
{
	t_camera	camera;
	t_ray		ray;

	set_camera(201, 101, M_PI_2, &camera);
	set_camera_transform(matrix_new_identity(4), &camera);
	ray_for_pixel(&camera, 0, 0, &ray);

	cr_expect(epsilon_eq(dbl, ray.start.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.start.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.start.z, 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, ray.direction.x, 0.66519, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.direction.y, 0.33259, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.direction.z, -0.66851, EPSILON));

	free_camera(&camera);
}

Test(camera, ray_camera_is_transformed)
{
	t_camera	camera;
	t_ray		ray;
	t_matrix	*rotate_y;
	t_matrix	*translate;
	t_matrix	*transform;

	rotate_y = matrix_rotate_y(M_PI_4);
	translate = matrix_translation(&(t_vec3){.x = 0.0, .y = -2.0, .z = 5.0});
	transform = matrix_multiply(rotate_y, translate);
	set_camera(201, 101, M_PI_2, &camera);
	set_camera_transform(transform, &camera);
	ray_for_pixel(&camera, 100, 50, &ray);

	cr_expect(epsilon_eq(dbl, ray.start.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.start.y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.start.z, -5.0, EPSILON));

	cr_expect(epsilon_eq(dbl, ray.direction.x, M_SQRT1_2, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.direction.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ray.direction.z, -M_SQRT1_2, EPSILON));

	free_camera(&camera);
	matrix_free(rotate_y);
	matrix_free(translate);
}

Test(camera, render_world_with_camera)
{
	t_camera	camera;
	t_scene		world;
	t_args		args;
	t_color		expected_color = {.r = 0.38066, .g = 0.47583, .b = 0.2855};

	init_args(&args, 11, 11);
	set_camera(11, 11, M_PI_2, &camera);
	set_camera_transform(view_transform(
		&(t_vec3){.x = 0.0, .y = 0.0, .z = -5.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 0.0},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 0.0}),
	&camera);
	set_default_world(&world);
	render_image(&camera, &world, &args.mlx_data);

	cr_expect(eq(uint, pixel_at(&args.mlx_data, 5, 5),
		convert_color(&expected_color)));

	free_camera(&camera);
	free_world(&world);
	close_graphics(&args);
}
