/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 04:24:52 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/23 14:41:45 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_sphere(t_obj *sphere, t_matrix *transform)
{
	t_material	material;

	material.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	material.ambient = 1.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.5;

	set_sphere(sphere, transform, &material);
}

Test(hit, hit_sphere_positive_values) {
	t_varray	*intersections;
	t_obj		sphere;
	int			first_idx;

	get_sphere(&sphere, matrix_new_identity(4));
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
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(hit, hit_sphere_negative_positive_values) {
	t_varray	*intersections;
	t_obj		sphere;
	int			first_idx;

	get_sphere(&sphere, matrix_new_identity(4));
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
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(hit, hit_sphere_negative_values) {
	t_varray	*intersections;
	t_obj		sphere;
	int			first_idx;

	get_sphere(&sphere, matrix_new_identity(4));
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
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(hit, hit_sphere_random_order) {
	t_varray	*intersections;
	t_obj		sphere;
	int			first_idx;

	get_sphere(&sphere, matrix_new_identity(4));
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
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}
