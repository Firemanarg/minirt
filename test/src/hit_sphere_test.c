/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 04:24:52 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 09:49:22 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include "v_array.h"
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

Test(hit, hit_sphere_positive_values) {
	t_varray	*intersections;
	t_obj		sphere;
	int			first_idx;

	get_sphere(&sphere);
	intersections = new_array(8);
	insert_into_array(intersections, 1, &sphere);
	insert_into_array(intersections, 2, &sphere);
	quicksort(intersections);
	first_idx = first_positive(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[first_idx].t,
				1.0, EPSILON));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[0].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[1].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[first_idx].obj,
				&sphere));
	free_array(intersections);
}

Test(hit, hit_sphere_negative_positive_values) {
	t_varray	*intersections;
	t_obj		sphere;
	int			first_idx;

	get_sphere(&sphere);
	intersections = new_array(8);
	insert_into_array(intersections, -1, &sphere);
	insert_into_array(intersections, 1, &sphere);
	quicksort(intersections);
	first_idx = first_positive(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				-1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[first_idx].t,
				1.0, EPSILON));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[0].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[1].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[first_idx].obj,
				&sphere));
	free_array(intersections);
}

Test(hit, hit_sphere_negative_values) {
	t_varray	*intersections;
	t_obj		sphere;
	int			first_idx;

	get_sphere(&sphere);
	intersections = new_array(8);
	insert_into_array(intersections, -2, &sphere);
	insert_into_array(intersections, -1, &sphere);
	quicksort(intersections);
	first_idx = first_positive(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				-2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				-1.0, EPSILON));
	cr_expect(eq(int, first_idx, -1));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[0].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[1].obj,
				&sphere));
	free_array(intersections);
}

Test(hit, hit_sphere_random_order) {
	t_varray	*intersections;
	t_obj		sphere;
	int			first_idx;

	get_sphere(&sphere);
	intersections = new_array(8);
	insert_into_array(intersections, 5, &sphere);
	insert_into_array(intersections, 7, &sphere);
	insert_into_array(intersections, -3, &sphere);
	insert_into_array(intersections, 2, &sphere);
	quicksort(intersections);
	first_idx = first_positive(intersections);
	cr_expect(eq(int, intersections->length, 4));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t,
				-3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t,
				2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[2].t,
				5.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[3].t,
				7.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[first_idx].t,
				2.0, EPSILON));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[0].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[1].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[2].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[3].obj,
				&sphere));
	cr_expect(eq(ptr, ((t_isect *)intersections->arr)[first_idx].obj,
				&sphere));
	free_array(intersections);
}
