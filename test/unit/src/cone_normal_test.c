/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_normal_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:38:17 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/26 02:43:04 by gmachado         ###   ########.fr       */
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

Test(cone_normal, surface_point_1)
{
	t_geom_obj	cone;
	t_vec3	point = {.x = 0, .y = 0, .z = 0};
	t_vec3	normal;

	get_cone(&cone, matrix_new_identity(4));
	cone.normal_at(&cone, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cone);
}

Test(cone_normal, surface_point_2)
{
	t_geom_obj	cone;
	t_vec3	point = {.x = 1, .y = 1, .z = 1};
	t_vec3	normal;

	get_cone(&cone, matrix_new_identity(4));
	cone.normal_at(&cone, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, -M_SQRT2, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 1.0, EPSILON));
	free_obj(&cone);
}

Test(cone_normal, surface_point_3)
{
	t_geom_obj	cone;
	t_vec3	point = {.x = -1, .y = -1, .z = 0};
	t_vec3	normal;

	get_cone(&cone, matrix_new_identity(4));
	cone.normal_at(&cone, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cone);
}
