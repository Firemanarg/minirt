/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:37:52 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/07 15:38:45 by gmachado         ###   ########.fr       */
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

	world->camera.transform = NULL;
	world->camera.inv_transform = NULL;
	world->camera.t_inv_transform = NULL;
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

static void	set_other_world(t_scene *world)
{
	const t_matrix_op	ops[2] = {
	{.op = TRANSLATE, .params = {.x = 0.0, .y = 0.0, .z = 10.0}}, {0}};
	t_material			m1;

	world->camera.transform = NULL;
	world->camera.inv_transform = NULL;
	world->camera.t_inv_transform = NULL;
	world->lights = malloc(sizeof(*(world->lights)) * 1);
	world->geometries = malloc(sizeof(*(world->geometries)) * 3);
	set_default_material(&m1);
	set_sphere(world->geometries, matrix_new_identity(4), &m1);
	set_sphere(world->geometries + 1, matrix_apply(matrix_new_identity(4),
			(t_matrix_op *)ops), &m1);
	world->lights[0] = (t_point_light){
		.pos = (t_vec3){.x = 0, .y = 0, .z = -10},
		.intensity = (t_color){.r = 1, .g = 1, .b = 1}};
	world->geometries[2] = (t_geom_obj){0};
}

Test(shadow, nothing_collinear_no_shadow)
{
	t_scene		world;
	t_vec3		point;
	t_precomp	comps;
	t_varray	*xs;

	xs = new_array(8);
	set_default_world(&world);
	set_vec3(0.0, 10.0, 0.0, &point);
	is_shadowed(&world, &point, &comps, xs);
	cr_expect(eq(int, comps.in_shadow, FALSE));
	free_world(&world);
	free_array(xs);
}

Test(shadow, object_between_point_and_light_shadow)
{
	t_scene		world;
	t_vec3		point;
	t_precomp	comps;
	t_varray	*xs;

	xs = new_array(8);
	set_default_world(&world);
	set_vec3(10.0, -10.0, 10.0, &point);
	is_shadowed(&world, &point, &comps, xs);
	cr_expect(eq(int, comps.in_shadow, TRUE));
	free_world(&world);
	free_array(xs);
}

Test(shadow, object_behind_light_no_shadow)
{
	t_scene		world;
	t_vec3		point;
	t_precomp	comps;
	t_varray	*xs;

	xs = new_array(8);
	set_default_world(&world);
	set_vec3(-20.0, 20.0, -20.0, &point);
	is_shadowed(&world, &point, &comps, xs);
	cr_expect(eq(int, comps.in_shadow, FALSE));
	free_world(&world);
	free_array(xs);
}

Test(shadow, object_behind_point_no_shadow)
{
	t_scene		world;
	t_vec3		point;
	t_precomp	comps;
	t_varray	*xs;

	xs = new_array(8);
	set_default_world(&world);
	set_vec3(-2.0, 2.0, -2.0, &point);
	is_shadowed(&world, &point, &comps, xs);
	cr_expect(eq(int, comps.in_shadow, FALSE));
	free_world(&world);
	free_array(xs);
}

Test(shadow, shade_hit_in_shadow)
{
	t_scene		world;
	t_precomp	comps;
	t_varray	*xs;
	t_ray		ray;
	t_isect		i;
	t_color		color;

	xs = new_array(8);
	set_other_world(&world);
	set_ray(&(t_vec3){.x = 0.0, .y = 0.0, .z = 5.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 1.0}, &ray);
	i.obj = world.geometries + 1;
	i.t = 4;
	prepare_computations(&i, &ray, &comps);
	shade_hit(&world, &comps, &color, xs);

	cr_expect(epsilon_eq(dbl, color.r, 0.1, EPSILON));
	cr_expect(epsilon_eq(dbl, color.g, 0.1, EPSILON));
	cr_expect(epsilon_eq(dbl, color.b, 0.1, EPSILON));

	free_world(&world);
	free_array(xs);
}

Test(shadow, hit_should_offset_point)
{
	t_geom_obj	sphere;
	t_precomp	comps;
	t_ray		ray;
	t_isect		i;
	const t_matrix_op	ops[2] = {
	{.op = TRANSLATE, .params = {.x = 0.0, .y = 0.0, .z = 1.0}}, {0}};
	t_material			m1;

	set_default_material(&m1);
	set_sphere(&sphere, matrix_apply(matrix_new_identity(4),
			(t_matrix_op *)ops), &m1);
	set_ray(&(t_vec3){.x = 0.0, .y = 0.0, .z = -5.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 1.0}, &ray);
	i.obj = &sphere;
	i.t = 5;
	prepare_computations(&i, &ray, &comps);

	cr_expect(comps.over_point.z < -EPSILON / 2);
	cr_expect(comps.point.z > comps.over_point.z);
}