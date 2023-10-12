/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:51:28 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 16:50:58 by gmachado         ###   ########.fr       */
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
	world->ambient_light.color = (t_color){.r = 1.0, .g = 1.0, .b = 1.0};
	world->lights = malloc(sizeof(*(world->lights)) * 2);
	world->geometries = malloc(sizeof(*(world->geometries)) * 3);
	set_material(&m1);
	set_sphere(world->geometries, matrix_new_identity(4), &m1);
	set_default_material(&m2);
	set_sphere(world->geometries + 1, matrix_apply(matrix_new_identity(4),
			(t_matrix_op *)ops), &m2);
	world->geometries[2] = (t_geom_obj){0};
	set_point_light(&(t_vec3){.x = -10.0, .y = 10.0, .z = -10.0},
					&(t_color){.r = 1.0, .g = 1.0, .b = 1.0}, world->lights);
	world->lights[1] = (t_point_light){0};
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

Test(world, shade_intersection)
{
	t_scene		w;
	t_ray		r;
	t_isect		i;
	t_precomp	comps;
	t_color		color;
	t_varray	*xs;

	xs = new_array(4);
	set_default_world(&w);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
			&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	i.obj = w.geometries;
	i.t = 4;
	prepare_computations(&i, &r, &comps);
	shade_hit(&w, &comps, &color, xs);
	cr_expect(epsilon_eq(dbl, color.r, 0.38066, EPSILON));
	cr_expect(epsilon_eq(dbl, color.g, 0.47583, EPSILON));
	cr_expect(epsilon_eq(dbl, color.b, 0.2855, EPSILON));
	free_world(&w);
	free_array(xs);
}

Test(world, shade_intersection_from_inside)
{
	t_scene		w;
	t_ray		r;
	t_isect		i;
	t_precomp	comps;
	t_color		color;
	t_varray	*xs;

	xs = new_array(4);
	set_default_world(&w);
	set_point_light(&(t_vec3){.x = 0, .y = 0.25, .z = 0},
		 &(t_color){.r = 1, .g = 1, .b = 1}, w.lights + 1);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = 0},
			&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	i.obj = w.geometries + 1;
	i.t = 0.5;
	prepare_computations(&i, &r, &comps);
	shade_hit(&w, &comps, &color, xs);
	cr_expect(epsilon_eq(dbl, color.r, 0.90498, EPSILON));
	cr_expect(epsilon_eq(dbl, color.g, 0.90498, EPSILON));
	cr_expect(epsilon_eq(dbl, color.b, 0.90498, EPSILON));
	free_world(&w);
	free_array(xs);
}

Test(world, color_on_ray_miss)
{
	t_scene		w;
	t_ray		r;
	t_color		color;
	t_varray	*xs;
	t_err		err;

	xs = new_array(8);
	set_default_world(&w);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
			&(t_vec3){.x = 0, .y = 1, .z = 0}, &r);
	err = color_at(&w, &r, xs, &color);
	cr_expect(eq(int, err, OK));
	cr_expect(epsilon_eq(dbl, color.r, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, color.g, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, color.b, 0.0, EPSILON));
	free_world(&w);
	free_array(xs);
}

Test(world, color_on_ray_hit)
{
	t_scene		w;
	t_ray		r;
	t_color		color;
	t_varray	*xs;
	t_err		err;

	xs = new_array(8);
	set_default_world(&w);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
			&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	err = color_at(&w, &r, xs, &color);
	cr_expect(eq(int, err, OK));
	cr_expect(epsilon_eq(dbl, color.r, 0.38066, EPSILON));
	cr_expect(epsilon_eq(dbl, color.g, 0.47583, EPSILON));
	cr_expect(epsilon_eq(dbl, color.b, 0.2855, EPSILON));
	free_world(&w);
	free_array(xs);
}

Test(world, color_on_intersection_behind_ray)
{
	t_scene		w;
	t_ray		r;
	t_color		color;
	t_varray	*xs;
	t_err		err;

	xs = new_array(8);
	set_default_world(&w);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = 0.75},
			&(t_vec3){.x = 0, .y = 0, .z = -1}, &r);
	w.geometries[0].material.ambient = 1.0;
	w.geometries[1].material.ambient = 1.0;
	err = color_at(&w, &r, xs, &color);
	cr_expect(eq(int, err, OK));
	cr_expect(epsilon_eq(dbl, color.r,
		w.geometries[1].material.color.r, EPSILON));
	cr_expect(epsilon_eq(dbl, color.g,
		w.geometries[1].material.color.g, EPSILON));
	cr_expect(epsilon_eq(dbl, color.b,
		w.geometries[1].material.color.b, EPSILON));
	free_world(&w);
	free_array(xs);
}
