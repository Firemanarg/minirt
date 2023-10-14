/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:59:59 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/24 19:38:44 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_cone(t_geom_obj *cone, t_matrix *transform)
{
	t_material	material;

	material.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	material.ambient = 1.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.5;

	set_cone(cone, transform, &material);
}

Test(cone_intersect, ray_hits_one_point_1)
{
	t_geom_obj		cone;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cone(&cone, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
		&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	normalize(&r.direction, &r.direction);
	err = cone.intersects(&cone, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &cone));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				5.0, EPSILON_TEST));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[1].obj, &cone));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[1].t,
				5.0, EPSILON_TEST));
	free_obj(&cone);
	free_array(xs);
}

Test(cone_intersect, ray_hits_one_point_2)
{
	t_geom_obj		cone;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cone(&cone, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
		&(t_vec3){.x = 1, .y = 1, .z = 1}, &r);
	normalize(&r.direction, &r.direction);
	err = cone.intersects(&cone, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &cone));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				8.66025, EPSILON_TEST));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[1].obj, &cone));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[1].t,
				8.66025, EPSILON_TEST));
	free_obj(&cone);
	free_array(xs);
}

Test(cone_intersect, ray_hits_two_points)
{
	t_geom_obj		cone;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cone(&cone, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 1, .y = 1, .z = -5},
		&(t_vec3){.x = -0.5, .y = -1, .z = 1}, &r);
	normalize(&r.direction, &r.direction);
	err = cone.intersects(&cone, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &cone));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				4.55006, EPSILON_TEST));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[1].obj, &cone));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[1].t,
				49.44994, EPSILON_TEST));
	free_obj(&cone);
	free_array(xs);
}

Test(cone_intersect, ray_parallel_to_one_half)
{
	t_geom_obj		cone;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cone(&cone, matrix_new_identity(4));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -1},
		&(t_vec3){.x = 0, .y = 1, .z = 1}, &r);
	normalize(&r.direction, &r.direction);
	err = cone.intersects(&cone, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 1));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &cone));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				0.35355, EPSILON_TEST));
	free_obj(&cone);
	free_array(xs);
}
