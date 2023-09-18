/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:47:33 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 12:37:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_sphere(t_obj *sphere)
{
	t_vec3	pos = {.x = 0, .y = 0, .z = 0};
	t_color	color = {.r = 255, .g = 0, .b = 0};

	sphere->pos = pos;
	sphere->color = color;
	sphere->type = SPHERE;
	sphere->diameter = 1.0;
	sphere->height = 0;
	sphere->intersects = (t_isect_func)sphere_intersect;
}

Test(intersect, hit_sphere_two_points) {
	t_varray	*intersections;
	t_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere);
	intersections = new_array(8);
	new_ray(&(t_vec3){.x = 0, .y = 0, .z =-5},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = sphere.intersects(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				6.0, EPSILON));
	free_array(intersections);
}

Test(intersect, hit_sphere_one_point) {
	t_varray	*intersections;
	t_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere);
	intersections = new_array(8);
	new_ray(&(t_vec3){.x = 0, .y = 1, .z =-5},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = sphere.intersects(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				5.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				5.0, EPSILON));
	free_array(intersections);
}

Test(intersect, hit_sphere_miss) {
	t_varray	*intersections;
	t_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere);
	intersections = new_array(8);
	new_ray(&(t_vec3){.x = 0, .y = 2, .z =-5},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = sphere.intersects(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 0));
	free_array(intersections);
}

Test(intersect, hit_sphere_ray_inside) {
	t_varray	*intersections;
	t_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere);
	intersections = new_array(8);
	new_ray(&(t_vec3){.x = 0, .y = 0, .z =0},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = sphere.intersects(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				-1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				1.0, EPSILON));
	free_array(intersections);
}

Test(intersect, hit_sphere_behind_ray) {
	t_varray	*intersections;
	t_obj		sphere;
	t_ray		ray;

	get_sphere(&sphere);
	intersections = new_array(8);
	new_ray(&(t_vec3){.x = 0, .y = 0, .z = 5},
		&(t_vec3){.x = 0, .y = 0, .z =1}, &ray);
	t_err err = sphere.intersects(&sphere, &ray, intersections);
	cr_expect(eq(int, err, OK));
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				-6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				-4.0, EPSILON));
	free_array(intersections);
}
