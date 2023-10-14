/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world_with_objects.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:51:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/13 03:53:26 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include <time.h>

static void	set_default_material(t_material *m)
{
	m->color = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->ambient = 0.1;
	m->shininess = 200.0;
}

static void	get_floor(t_geom_obj *floor)
{
	t_material	m;

	set_default_material(&m);
	m.color = (t_color){.r = 1.0, .g = 0.9, .b = 0.9};
	m.specular = 0.0;
	set_plane(floor,
		matrix_new_identity(4), &m);
	floor->map_uv = plane_map_uv;
	floor->checkers.c1 = (t_color){.r = 0.5, .g = 0.5, .b = 0.5};
	floor->checkers.c2 = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	floor->checkers.height = 2;
	floor->checkers.width = 2;
}

static void	get_left_wall(t_geom_obj *left_wall)
{
	t_material	m;
	t_matrix_op mops[4] = {
	{.op = ROTATE_X, .param = M_PI_2},
	{.op = ROTATE_Y, .param = -M_PI_4},
	{.op = TRANSLATE, .params = {.x = 0.0, .y = 0.0, .z = 5.0}},
	{0}};

	set_default_material(&m);
	m.color = (t_color){.r = 1.0, .g = 0.9, .b = 0.9};
	m.specular = 0.0;
	set_plane(left_wall, matrix_apply(matrix_new_identity(4), mops), &m);
	left_wall->map_uv = plane_map_uv;
	left_wall->checkers.c1 = (t_color){.r = 0.5, .g = 0.5, .b = 0.5};
	left_wall->checkers.c2 = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	left_wall->checkers.height = 2;
	left_wall->checkers.width = 2;
}

static void	get_right_wall(t_geom_obj *right_wall)
{
	t_material	m;
	t_matrix_op mops[4] = {
	{.op = ROTATE_X, .param = M_PI_2},
	{.op = ROTATE_Y, .param = M_PI_4},
	{.op = TRANSLATE, .params = {.x = 0.0, .y = 0.0, .z = 5.0}},
	{0}};

	set_default_material(&m);
	m.color = (t_color){.r = 1.0, .g = 0.9, .b = 0.9};
	m.specular = 0.0;
	set_plane(right_wall, matrix_apply(matrix_new_identity(4), mops), &m);
	right_wall->map_uv = plane_map_uv;
	right_wall->checkers.c1 = (t_color){.r = 0.5, .g = 0.5, .b = 0.5};
	right_wall->checkers.c2 = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	right_wall->checkers.height = 2;
	right_wall->checkers.width = 2;
}

static void	get_large_cylinder(t_geom_obj *cylinder)
{
	t_material	m;
	t_matrix_op mops[4] = {
	{.op = ROTATE_X, .param = -M_PI_4},
	{.op = ROTATE_Y, .param = M_PI_4 / 2},
	{.op = TRANSLATE, .params = {.x = -0.5, .y = 1.0, .z = 0.5}},
	{0}};

	set_default_material(&m);
	m.color = (t_color){.r = 0.1, .g = 1.0, .b = 0.5};
	m.diffuse = 0.7;
	m.specular = 0.3;
	set_cylinder(cylinder,
		matrix_apply(matrix_new_identity(4), mops), &m);
	set_object_limits(cylinder, 0.0, 1.5, TRUE);
	cylinder->map_uv = cylinder_map_uv;
	cylinder->checkers.c1 = (t_color){.r = 0.0, .g = 0.0, .b = 0.5};
	cylinder->checkers.c2 = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	cylinder->checkers.height = 8;
	cylinder->checkers.width = 8;
}

static void	get_medium_cone(t_geom_obj *cone)
{
	t_material	m;
	t_matrix_op mops[5] = {
	{.op = ROTATE_X, .param = -M_PI_4},
	{.op = ROTATE_Y, .param = -M_PI_4 / 2},
	{.op = SCALE, .params = {.x = 0.5, .y = 0.5, .z = 0.5}},
	{.op = TRANSLATE, .params = {.x = 1.5, .y = 0.5, .z = -0.5}},
	{0}};

	set_default_material(&m);
	m.color = (t_color){.r = 0.50, .g = 1.0, .b = 0.1};
	m.diffuse = 0.7;
	m.specular = 0.3;
	set_cone(cone, matrix_apply(matrix_new_identity(4), mops), &m);
	set_object_limits(cone, 0.0, 1.5, TRUE);
	cone->map_uv = cone_map_uv;
	cone->checkers.c1 = (t_color){.r = 0.5, .g = 0.0, .b = 0.0};
	cone->checkers.c2 = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	cone->checkers.height = 8;
	cone->checkers.width = 8;
}

static void	get_small_sphere(t_geom_obj *sphere)
{
	t_material	m;
	t_matrix_op mops[3] = {
	{.op = SCALE, .params = {.x = 0.33, .y = 0.33, .z = 0.33}},
	{.op = TRANSLATE, .params = {.x = -1.5, .y = 0.33, .z = -0.75}},
	{0}};

	set_default_material(&m);
	m.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	m.diffuse = 0.7;
	m.specular = 0.3;
	set_sphere(sphere, matrix_apply(matrix_new_identity(4), mops), &m);
	sphere->map_uv = sphere_map_uv;
	sphere->checkers.c1 = (t_color){.r = 0.0, .g = 0.5, .b = 0.0};
	sphere->checkers.c2 = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	sphere->checkers.height = 8;
	sphere->checkers.width = 8;
}

static void	get_camera(t_camera *camera, int width, int height)
{
	set_camera(width, height, M_PI / 3.0, camera);
	set_camera_transform(view_transform(
		&(t_vec3){.x = -2.0, .y = 1.5, .z = -6.0},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 0.0},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 0.0}),
	camera);
}

static void	get_world(t_scene *world, int width, int height)
{
	get_camera(&world->camera, width, height);
	world->geometries = malloc(sizeof(t_geom_obj) * 7);
	get_floor(world->geometries);
	get_left_wall(world->geometries + 1);
	get_right_wall(world->geometries + 2);
	get_large_cylinder(world->geometries + 3);
	get_medium_cone(world->geometries + 4);
	get_small_sphere(world->geometries + 5);
	world->geometries[6] = (t_geom_obj){0};
	world->ambient_light.color = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	world->lights = malloc(sizeof(t_point_light) * 2);
	set_point_light(&(t_vec3){.x = -10.0, .y = 10.0, .z = -10.0},
					&(t_color){.r = 1.0, .g = 1.0, .b = 1.0}, world->lights);
	world->lights[3] = (t_point_light){0};
}

int	main(void)
{
	t_args			args;
	int				width = 800;
	int				height = 600;
	t_scene			world;
	struct timespec	begin, end;

	clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
	init_args(&args, width, height);
	get_world(&world, width, height);
	render_image(&world.camera, &world, &args.mlx_data);
	free_world(&world);
	mlx_put_image_to_window(args.mlx, args.mlx_win,
		args.mlx_data.img, 0, 0);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	printf("Rendered in %.0f ms.\n", (end.tv_nsec - begin.tv_nsec) / 1000000.0
		+ (end.tv_sec - begin.tv_sec) * 1000.0);
	mlx_hook(args.mlx_win, ON_DESTROY,
		MASK_STRUCTURE_NOTIFY, on_destroy, &args);
	mlx_hook(args.mlx_win, ON_KEYDOWN, MASK_KEY_PRESS, on_key_press, &args);
	mlx_loop(args.mlx);
	return (0);
}
