/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:35:42 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/24 07:47:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_plane(t_obj *plane, t_matrix *transform)
{
	t_material	material;

	material.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	material.ambient = 1.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.5;

	set_plane(plane, transform, &material);
}

Test(plane, normal_is_constant_everywhere)
{
	t_obj	plane;
	t_vec3	normal;

	get_plane(&plane, matrix_new_identity(4));
	plane.normal_at(&plane, &(t_vec3){.x = 0, .y = 0, .z = 0}, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	plane.normal_at(&plane, &(t_vec3){.x = 10, .y = 0, .z = -10}, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	plane.normal_at(&plane, &(t_vec3){.x = -5, .y = 0, .z = 150}, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&plane);
}

Test(plane, intersect_with_parallel_ray)
{
	t_obj		plane;
	t_ray		r;
	t_varray	*xs;

	get_plane(&plane, matrix_new_identity(4));
	xs = new_array(1);
	new_ray(&(t_vec3){.x = 0, .y = 10, .z = 0},
		&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	plane.intersects(&plane, &r, xs);
	cr_expect(eq(int, xs->capacity, 1));
	cr_expect(eq(int, xs->length, 0));
	free_obj(&plane);
	free_array(xs);
}

Test(plane, intersect_with_coplanar_ray)
{
	t_obj		plane;
	t_ray		r;
	t_varray	*xs;

	get_plane(&plane, matrix_new_identity(4));
	xs = new_array(1);
	new_ray(&(t_vec3){.x = 0, .y = 0, .z = 0},
		&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	plane.intersects(&plane, &r, xs);
	cr_expect(eq(int, xs->capacity, 1));
	cr_expect(eq(int, xs->length, 0));
	free_obj(&plane);
	free_array(xs);
}

Test(plane, intersect_from_above)
{
	t_obj		plane;
	t_ray		r;
	t_varray	*xs;

	get_plane(&plane, matrix_new_identity(4));
	xs = new_array(1);
	new_ray(&(t_vec3){.x = 0, .y = 1, .z = 0},
		&(t_vec3){.x = 0, .y = -1, .z = 0}, &r);
	plane.intersects(&plane, &r, xs);
	cr_expect(eq(int, xs->capacity, 1));
	cr_expect(eq(int, xs->length, 1));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &plane));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				1.0, EPSILON));
	free_obj(&plane);
	free_array(xs);
}

Test(plane, intersect_from_below)
{
	t_obj		plane;
	t_ray		r;
	t_varray	*xs;

	get_plane(&plane, matrix_new_identity(4));
	xs = new_array(1);
	new_ray(&(t_vec3){.x = 0, .y = -1, .z = 0},
		&(t_vec3){.x = 0, .y = 1, .z = 0}, &r);
	plane.intersects(&plane, &r, xs);
	cr_expect(eq(int, xs->capacity, 1));
	cr_expect(eq(int, xs->length, 1));
	cr_expect(eq(ptr, ((t_isect *)xs->arr)[0].obj, &plane));
	cr_expect(epsilon_eq(dbl, ((t_isect *)xs->arr)[0].t,
				1.0, EPSILON));
	free_obj(&plane);
	free_array(xs);
}
