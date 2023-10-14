/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:59:59 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 19:38:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_cylinder(t_geom_obj *cylinder, t_matrix *transform)
{
	t_material	material;

	material.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	material.ambient = 1.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.5;

	set_cylinder(cylinder, transform, &material);
}

Test(cylinder_intersect, parallel_ray_on_surface_misses)
{
	t_geom_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 1, .y = 0, .z = 0},
		&(t_vec3){.x = 0, .y = 1, .z = 0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	cr_expect(eq(int, xs->capacity, 2));
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cylinder);
	free_array(xs);
}

Test(cylinder_intersect, parallel_ray_inside_misses)
{
	t_geom_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = 0},
		&(t_vec3){.x = 0, .y = 1, .z = 0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	cr_expect(eq(int, xs->capacity, 2));
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cylinder);
	free_array(xs);
}

Test(cylinder_intersect, parallel_ray_outside_misses)
{
	t_geom_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
		&(t_vec3){.x = 1, .y = 1, .z = 1}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	cr_expect(eq(int, xs->capacity, 2));
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cylinder);
	free_array(xs);
}

Test(cylinder_intersect, ray_hits_one_point)
{
	t_geom_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 1, .y = 0, .z = -5},
		&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &cylinder));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				5.0, EPSILON_TEST));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[1].obj, &cylinder));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[1].t,
				5.0, EPSILON_TEST));
	free_obj(&cylinder);
	free_array(xs);
}

Test(cylinder_intersect, ray_hits_two_points_1)
{
	t_geom_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
		&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &cylinder));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				4.0, EPSILON_TEST));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[1].obj, &cylinder));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[1].t,
				6.0, EPSILON_TEST));
	free_obj(&cylinder);
	free_array(xs);
}

Test(cylinder_intersect, ray_hits_two_points_2)
{
	t_geom_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.5, .y = 0, .z = -5},
		&(t_vec3){.x = 0.1, .y = 1, .z = 1}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &cylinder));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				6.80798, EPSILON_TEST));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[1].obj, &cylinder));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[1].t,
				7.08872, EPSILON_TEST));
	free_obj(&cylinder);
	free_array(xs);
}
