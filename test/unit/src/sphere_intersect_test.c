/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:47:33 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 05:04:12 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_sphere(t_geom_obj *sphere, t_matrix *transform)
{
	t_material	material;

	material.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	material.ambient = 1.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.5;

	set_sphere(sphere, transform, &material);
}

Test(intersect, intersect_sphere_two_points) {
	t_varray	*intersections;
	t_geom_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere, matrix_new_identity(4));
	intersections = new_array(8);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z =-5},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = obj_intersect(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				6.0, EPSILON));
	free_array(intersections);
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(intersect, intersect_sphere_one_point) {
	t_varray	*intersections;
	t_geom_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere, matrix_new_identity(4));
	intersections = new_array(8);
	set_ray(&(t_vec3){.x = 0, .y = 1, .z =-5},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = obj_intersect(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				5.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				5.0, EPSILON));
	free_array(intersections);
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(intersect, intersect_sphere_miss) {
	t_varray	*intersections;
	t_geom_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere, matrix_new_identity(4));
	intersections = new_array(8);
	set_ray(&(t_vec3){.x = 0, .y = 2, .z =-5},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = obj_intersect(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 0));
	free_array(intersections);
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(intersect, intersect_sphere_ray_inside) {
	t_varray	*intersections;
	t_geom_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere, matrix_new_identity(4));
	intersections = new_array(8);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z =0},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = obj_intersect(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				-1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				1.0, EPSILON));
	free_array(intersections);
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(intersect, intersect_sphere_behind_ray) {
	t_varray	*intersections;
	t_geom_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere, matrix_new_identity(4));
	intersections = new_array(8);
	set_ray(&(t_vec3){.x = 0, .y = 0, .z = 5},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = obj_intersect(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				-6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				-4.0, EPSILON));
	free_array(intersections);
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}
