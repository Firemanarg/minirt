/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:51:28 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/05 04:40:04 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_test.h"

static void	set_material(t_material *m)
{
	m->color = (t_color){.r = 0.8, .b = 1.0, .g = 0.6};
	m->diffuse = 0.7;
	m->specular = 0.2;
	m->ambient = 0.2;
	m->shininess = 200;
}

static void	set_default_world(t_scene *world)
{
	const t_matrix_op	ops[2] = {
	{.op = SCALE, .params = {.x = 0.5, .y = 0.5, .z = 0.5}}, {0}};
	t_material			m;

	world->lights = malloc(sizeof(*(world->lights)) * 1);
	world->geometries = malloc(sizeof(*(world->geometries)) * 3);
	set_material(&m);
	set_sphere(world->geometries, matrix_new_identity(4), &m);
	set_sphere(world->geometries + 1, matrix_apply(matrix_new_identity(4),
			(t_matrix_op *)ops), &m);
	world->lights[0] = (t_point_light){
		.pos = (t_vec3){.x = -10, .y = 10, .z = -10},
		.intensity = (t_color){.r = 1, .g = 1, .b = 1}};
	world->geometries[2] = (t_geom_obj){0};
}

Test(world, intersect_world_with_ray)
{
	t_scene			w;
	t_ray			r;
	t_varray		*xs;
	t_err			err;

	xs = new_array(4);
	set_default_world(&w);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
			&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	err = intersect_world(&w, &r, xs);
	cr_expect(eq(int, err, OK));
	cr_expect(eq(int, xs->capacity, 4));
	cr_expect(eq(int, xs->length, 4));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[1].t,
				4.5, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[2].t,
				5.5, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[3].t,
				6.0, EPSILON));
	free_world(&w);
}

Test(world, prepare_computations)
{
	t_ray		r;
	t_geom_obj	sphere;
	t_material	m;
	t_isect		i;
	t_precomp	comps;

	set_material(&m);
	set_sphere(&sphere, matrix_new_identity(4), &m);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
			&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	i.obj = &sphere;
	i.t = 4;
	prepare_computations(&i, &r, &comps);
	cr_expect(epsilon_eq(dbl, comps.t, 4.0, EPSILON));
	cr_expect(eq(ptr, comps.obj, &sphere));

	cr_expect(epsilon_eq(dbl, comps.point.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.point.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.point.z, -1.0, EPSILON));

	cr_expect(epsilon_eq(dbl, comps.eye.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.eye.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.eye.z, -1.0, EPSILON));

	cr_expect(epsilon_eq(dbl, comps.normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.normal.z, -1.0, EPSILON));

	free_obj(&sphere);
}

Test(world, hit_outside)
{
	t_ray		r;
	t_geom_obj	sphere;
	t_material	m;
	t_isect		i;
	t_precomp	comps;

	set_material(&m);
	set_sphere(&sphere, matrix_new_identity(4), &m);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
			&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	i.obj = &sphere;
	i.t = 4;
	prepare_computations(&i, &r, &comps);
	cr_expect(eq(int, comps.inside, FALSE));

	free_obj(&sphere);
}

Test(world, hit_inside)
{
	t_ray		r;
	t_geom_obj	sphere;
	t_material	m;
	t_isect		i;
	t_precomp	comps;

	set_material(&m);
	set_sphere(&sphere, matrix_new_identity(4), &m);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = 0},
			&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	i.obj = &sphere;
	i.t = 1;
	prepare_computations(&i, &r, &comps);
	cr_expect(eq(int, comps.inside, TRUE));

	cr_expect(epsilon_eq(dbl, comps.point.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.point.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.point.z, 1.0, EPSILON));

	cr_expect(epsilon_eq(dbl, comps.eye.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.eye.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.eye.z, -1.0, EPSILON));

	cr_expect(epsilon_eq(dbl, comps.normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, comps.normal.z, -1.0, EPSILON));

	free_obj(&sphere);
}