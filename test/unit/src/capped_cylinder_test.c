/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capped_cylinder_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:24:33 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/05 03:30:38 by gmachado         ###   ########.fr       */
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

Test(capped_cylinder, default_cylinder_is_open)
{
	t_obj	cylinder;

	get_cylinder(&cylinder, matrix_new_identity(4));
	cr_expect(eq(int, cylinder.is_closed, FALSE));
	free_obj(&cylinder);
}

Test(capped_cylinder, intersect_from_above_hit_caps)
{
	t_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = 3.0, .z = 0.0},
		&(t_vec3){.x = 0.0, .y = -1.0, .z = 0.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	free_obj(&cylinder);
	free_array(xs);
}

Test(capped_cylinder, intersect_from_above_hit_cap_and_side)
{
	t_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = 3.0, .z = -2.0},
		&(t_vec3){.x = 0.0, .y = -1.0, .z = 2.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	free_obj(&cylinder);
	free_array(xs);
}

Test(capped_cylinder, intersect_from_above_hit_cap_and_corner)
{
	t_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = 4.0, .z = -2.0},
		&(t_vec3){.x = 0.0, .y = -1.0, .z = 1.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	free_obj(&cylinder);
	free_array(xs);
}

Test(capped_cylinder, intersect_from_below_hit_cap_and_side)
{
	t_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = 0.0, .z = -2.0},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 2.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	free_obj(&cylinder);
	free_array(xs);
}

Test(capped_cylinder, intersect_from_below_hit_cap_and_corner)
{
	t_obj		cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = -1.0, .z = -2.0},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 1.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	free_obj(&cylinder);
	free_array(xs);
}

Test(capped_cylinder, normal_bottom_cap_1)
{
	t_obj	cylinder;
	t_vec3	point = (t_vec3){.x = 0.0, .y = 1.0, .z = 0.0};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	obj_normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cylinder);
}

Test(capped_cylinder, normal_bottom_cap_2)
{
	t_obj	cylinder;
	t_vec3	point = (t_vec3){.x = 0.5, .y = 1.0, .z = 0.0};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	obj_normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cylinder);
}

Test(capped_cylinder, normal_bottom_cap_3)
{
	t_obj	cylinder;
	t_vec3	point = (t_vec3){.x = 0.0, .y = 1.0, .z = 0.5};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	obj_normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cylinder);
}

Test(capped_cylinder, normal_top_cap_1)
{
	t_obj	cylinder;
	t_vec3	point = (t_vec3){.x = 0.0, .y = 2.0, .z = 0.0};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	obj_normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cylinder);
}

Test(capped_cylinder, normal_top_cap_2)
{
	t_obj	cylinder;
	t_vec3	point = (t_vec3){.x = 0.5, .y = 2.0, .z = 0.0};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	obj_normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cylinder);
}

Test(capped_cylinder, normal_top_cap_3)
{
	t_obj	cylinder;
	t_vec3	point = (t_vec3){.x = 0.0, .y = 2.0, .z = 0.5};
	t_vec3	normal;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, TRUE);
	cr_expect(eq(int, cylinder.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	obj_normal_at(&cylinder, &point, &normal);
	cr_expect(epsilon_eq(dbl, normal.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, normal.z, 0.0, EPSILON));
	free_obj(&cylinder);
}
