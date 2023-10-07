/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncated_cylinder_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:49:44 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/05 03:33:27 by gmachado         ###   ########.fr       */
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

Test(truncated_cylinder, default_cylinder_is_infinite)
{
	t_obj	cylinder;

	get_cylinder(&cylinder, matrix_new_identity(4));
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 1.0/0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, -1.0/0.0, EPSILON));
	free_obj(&cylinder);
}

Test(truncated_cylinder, intersect_diagonal_ray_inside_miss)
{
	t_obj	cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, FALSE);
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 1.5, .z = 0.0},
		&(t_vec3){.x = 0.1, .y = 1.0, .z = 0.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cylinder);
	free_array(xs);
}

Test(truncated_cylinder, intersect_ray_perp_y_above_miss)
{
	t_obj	cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, FALSE);
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = 3.0, .z = -5.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 1.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cylinder);
	free_array(xs);
}

Test(truncated_cylinder, intersect_ray_perp_y_below_miss)
{
	t_obj	cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, FALSE);
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = 0.0, .z = -5.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 1.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cylinder);
	free_array(xs);
}

Test(truncated_cylinder, intersect_ray_at_maximum_miss)
{
	t_obj	cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, FALSE);
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 2.0, .z = -5.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 1.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cylinder);
	free_array(xs);
}

Test(truncated_cylinder, intersect_ray_at_minimum_miss)
{
	t_obj	cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, FALSE);
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 1.0, .z = -5.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 1.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cylinder);
	free_array(xs);
}

Test(truncated_cylinder, intersect_ray_at_middle_hit)
{
	t_obj	cylinder;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cylinder(&cylinder, matrix_new_identity(4));
	set_cylinder_limits(&cylinder, 1.0, 2.0, FALSE);
	cr_expect(epsilon_eq(dbl, cylinder.maximum, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, cylinder.minimum, 1.0, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0, .y = 1.5, .z = -2.0},
		&(t_vec3){.x = 0.0, .y = 0.0, .z = 1.0}, &r);
	err = obj_intersect(&cylinder, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	free_obj(&cylinder);
	free_array(xs);
}
