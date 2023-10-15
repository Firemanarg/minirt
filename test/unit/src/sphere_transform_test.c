/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_transform_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 02:49:25 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 13:41:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static t_err	get_sphere(t_geom_obj *sphere, t_matrix *transform)
{
	t_material	material;

	material.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	material.ambient = 1.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.5;

	return (set_sphere(sphere, transform, &material));
}

Test(sphere_transform, sphere_transform_identity)
{
	t_geom_obj	sphere;
	t_err	err = get_sphere(&sphere, matrix_new_identity(4));

	cr_assert(eq(int, err, OK));

	cr_expect(epsilon_eq(dbl, sphere.transform->data[0][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[0][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[0][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, sphere.transform->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[1][1], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[1][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, sphere.transform->data[2][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[2][2], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[2][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, sphere.transform->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[3][3], 1.0, EPSILON));

	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(sphere_transform, sphere_transform_change)
{
	t_geom_obj	sphere;
	t_err	err = get_sphere(&sphere, matrix_new_identity(4));

	cr_assert(eq(int, err, OK));
	err = set_object_transform(&sphere,
			matrix_translation(&(t_vec3){.x = 2, .y = 3, .z = 4}));

	cr_assert(eq(int, err, OK));

	cr_expect(epsilon_eq(dbl, sphere.transform->data[0][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[0][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[0][3], 2.0, EPSILON));

	cr_expect(epsilon_eq(dbl, sphere.transform->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[1][1], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[1][3], 3.0, EPSILON));

	cr_expect(epsilon_eq(dbl, sphere.transform->data[2][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[2][2], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[2][3], 4.0, EPSILON));

	cr_expect(epsilon_eq(dbl, sphere.transform->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, sphere.transform->data[3][3], 1.0, EPSILON));

	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
}

Test(sphere_transform, intersect_scaled_ray)
{
	t_geom_obj	sphere;
	t_ray		r;
	t_varray	*intersections;

	set_ray(&(t_vec3){.x = 0, .y = 0, .z = -5},
					&(t_vec3){.x = 0, .y = 0, .z = 1}, &r);
	t_err	err = get_sphere(&sphere, matrix_new_identity(4));

	cr_assert(eq(int, err, OK));
	intersections = new_array(2);
	cr_assert(ne(ptr, intersections, NULL));
	err = set_object_transform(&sphere,
			matrix_scaling(&(t_vec3){.x = 2, .y = 2, .z = 2}));
	cr_assert(eq(int, err, OK));

	obj_intersect(&sphere, &r, intersections);
	quicksort(intersections);
	cr_expect(eq(int, intersections->length, 2));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[0].t, 3.0,
		EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)intersections->arr)[1].t, 7.0,
		EPSILON));
	matrix_free(sphere.transform);
	matrix_free(sphere.inv_transform);
	free_array(intersections);
}
