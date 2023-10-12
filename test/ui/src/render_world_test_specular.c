/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world_test_specular.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:51:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 04:36:01 by gmachado         ###   ########.fr       */
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

static void	get_wall(t_geom_obj *wall)
{
	t_material	m;
	t_matrix_op mops[3] = {
	{.op = ROTATE_X, .param = M_PI_2},
	{.op = TRANSLATE, .params = {.x = 0.0, .y = 0.0, .z = 10.0}},
	{0}};

	set_default_material(&m);
	m.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	set_plane(wall, matrix_apply(matrix_new_identity(4), mops), &m);
}

static void	get_cylinder(t_geom_obj *cylinder)
{
	t_material	m;
	t_matrix_op mops[3] = {
	{.op = ROTATE_X, .param = M_PI_2},
	{.op = TRANSLATE, .params = {.x = 0.0, .y = 0.0, .z = 3.0}},
	{0}};

	set_default_material(&m);
	m.color = (t_color){.r = 0.0, .g = 0.0, .b = 1.0};
	set_cylinder(cylinder, matrix_apply(matrix_new_identity(4), mops), &m);
	set_object_limits(cylinder, 0.1, 0.5, FALSE);
}

static void	get_camera(t_camera *camera, int width, int height)
{
	set_camera(width, height, M_PI / 3.0, camera);
	set_camera_transform(view_transform(
		&(t_vec3){.x = 0.0, .y = 0., .z = 0.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 5.0},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 0.0}),
	camera);
}

static void	get_world(t_scene *world, int width, int height)
{
	get_camera(&world->camera, width, height);
	world->geometries = malloc(sizeof(t_geom_obj) * 3);
	get_wall(world->geometries);
	get_cylinder(world->geometries + 1);
	world->geometries[2] = (t_geom_obj){0};
	world->ambient_light.color = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	world->lights = malloc(sizeof(t_point_light) * 2);
	set_point_light(&(t_vec3){.x = 0.0, .y = 0.0, .z = -10.0},
					&(t_color){.r = 1.0, .g = 1.0, .b = 1.0}, world->lights);
	world->lights[1] = (t_point_light){0};
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
