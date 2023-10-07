/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:14:09 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/26 02:44:49 by gmachado         ###   ########.fr       */
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

Test(sphere_normal, default_sphere_x_axis)
{
	t_obj	sphere;
	t_vec3	normal;
	t_vec3	point = {.x = 1, .y = 0, .z = 0};

	get_sphere(&sphere, matrix_new_identity(4));
	obj_normal_at(&sphere, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));

	free_obj(&sphere);
}

Test(sphere_normal, default_sphere_y_axis)
{
	t_obj	sphere;
	t_vec3	normal;
	t_vec3	point = {.x = 0, .y = 1, .z = 0};

	get_sphere(&sphere, matrix_new_identity(4));
	obj_normal_at(&sphere, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));

	free_obj(&sphere);
}

Test(sphere_normal, default_sphere_z_axis)
{
	t_obj	sphere;
	t_vec3	normal;
	t_vec3	point = {.x = 0, .y = 0, .z = 1};

	get_sphere(&sphere, matrix_new_identity(4));
	obj_normal_at(&sphere, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 1.0, EPSILON));

	free_obj(&sphere);
}

Test(sphere_normal, default_sphere_non_axial)
{
	t_obj	sphere;
	t_vec3	normal;
	double	sqrt_3_over_3 = sqrt(3.0) / 3.0;
	t_vec3	point = {.x = sqrt_3_over_3, .y = sqrt_3_over_3,
				.z = sqrt_3_over_3};


	get_sphere(&sphere, matrix_new_identity(4));
	obj_normal_at(&sphere, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, sqrt_3_over_3, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, sqrt_3_over_3, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, sqrt_3_over_3, EPSILON));

	free_obj(&sphere);
}

Test(sphere_normal, translated_sphere)
{
	t_obj	sphere;
	t_vec3	normal;
	t_vec3	point = {.x = 0, .y = 1.70711,
				.z = -0.70711};


	get_sphere(&sphere, matrix_translation(&(t_vec3){.x = 0, .y = 1, .z = 0}));
	obj_normal_at(&sphere, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y,0.70711, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, -0.70711, EPSILON));

	free_obj(&sphere);
}

Test(sphere_normal, transformed_sphere)
{
	t_obj	sphere;
	t_vec3	normal;
	t_vec3	point = {.x = 0.0, .y = M_SQRT1_2,
				.z = -M_SQRT1_2};
	t_matrix_op	mop[3] = {
		{.op = ROTATE_Z, .param = M_PI / 5.0},
		{.op = SCALE, .params = {.x = 1.0, .y = 0.5, .z = 1.0}},
		{.op = NOP}};


	get_sphere(&sphere, matrix_apply(matrix_new_identity(4), mop));
	obj_normal_at(&sphere, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y,0.97014, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, -0.24254, EPSILON));
	free_obj(&sphere);
}