/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:38:17 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/24 17:47:52 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_cylinder(t_obj *cylinder, t_matrix *transform)
{
	t_material	material;

	material.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	material.ambient = 1.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.5;

	set_cylinder(cylinder, transform, &material);
}

Test(cylinder_normal, surface_point_1)
{
	t_obj	cylinder;
	t_vec3	point = {.x = 1, .y = 0, .z = 0};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	cylinder.normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cylinder);
}

Test(cylinder_normal, surface_point_2)
{
	t_obj	cylinder;
	t_vec3	point = {.x = 0, .y = 5, .z = -1};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	cylinder.normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, -1.0, EPSILON));
	free_obj(&cylinder);
}

Test(cylinder_normal, surface_point_3)
{
	t_obj	cylinder;
	t_vec3	point = {.x = 0, .y = -2, .z = 1};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	cylinder.normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 1.0, EPSILON));
	free_obj(&cylinder);
}

Test(cylinder_normal, surface_point_4)
{
	t_obj	cylinder;
	t_vec3	point = {.x = -1, .y = 1, .z = 0};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	cylinder.normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cylinder);
}
