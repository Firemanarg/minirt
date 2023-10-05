/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capped_cone_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:24:33 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/26 02:42:37 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_cone(t_obj *cone, t_matrix *transform)
{
	t_material	material;

	material.color = (t_color){.r = 1.0, .g = 0.0, .b = 0.0};
	material.ambient = 1.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.5;

	set_cone(cone, transform, &material);
}

Test(capped_cone, default_cone_is_open)
{
	t_obj	cone;

	get_cone(&cone, matrix_new_identity(4));
	cr_expect(eq(int, cone.is_closed, FALSE));
	free_obj(&cone);
}

Test(capped_cone, ray_misses)
{
	t_obj		cone;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cone(&cone, matrix_new_identity(4));
	set_cone_limits(&cone, -0.5, 0.5, TRUE);
	cr_expect(eq(int, cone.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cone.maximum, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, cone.minimum, -0.5, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = 0.0, .z = -5.0},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 0.0}, &r);
	err = obj_intersect(&cone, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 0));
	free_obj(&cone);
	free_array(xs);
}

Test(capped_cone, ray_hits_twice)
{
	t_obj		cone;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cone(&cone, matrix_new_identity(4));
	set_cone_limits(&cone, -0.5, 0.5, TRUE);
	cr_expect(eq(int, cone.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cone.maximum, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, cone.minimum, -0.5, EPSILON));
	xs = new_array(2);
	set_ray(&(t_vec3){.x = 0.0, .y = 0.0, .z = -0.25},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 1.0}, &r);
	normalize(&r.direction, &r.direction);
	err = cone.intersects(&cone, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 2));
	free_obj(&cone);
	free_array(xs);
}

Test(capped_cone, ray_hits_four_times)
{
	t_obj		cone;
	t_ray		r;
	t_varray	*xs;
	t_err 		err;

	get_cone(&cone, matrix_new_identity(4));
	set_cone_limits(&cone, -0.5, 0.5, TRUE);
	cr_expect(eq(int, cone.is_closed, TRUE));
	cr_expect(epsilon_eq(dbl, cone.maximum, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, cone.minimum, -0.5, EPSILON));
	xs = new_array(4);
	set_ray(&(t_vec3){.x = 0.0, .y = 0.0, .z = -0.25},
		&(t_vec3){.x = 0.0, .y = 1.0, .z = 0.0}, &r);
	normalize(&r.direction, &r.direction);
	err = cone.intersects(&cone, &r, xs);
	cr_expect(eq(int, err, OK));
	quicksort(xs);
	cr_expect(eq(int, xs->length, 4));
	free_obj(&cone);
	free_array(xs);
}
