/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:08:48 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 19:37:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_test.h"

static void compare_matrices(t_matrix *t, t_matrix *expected)
{
	cr_expect(epsilon_eq(dbl, t->data[0][0], expected->data[0][0], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[0][1], expected->data[0][1], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[0][2], expected->data[0][2], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[0][3], expected->data[0][3], EPSILON_TEST));

	cr_expect(epsilon_eq(dbl, t->data[1][0], expected->data[1][0], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[1][1], expected->data[1][1], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[1][2], expected->data[1][2], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[1][3], expected->data[1][3], EPSILON_TEST));

	cr_expect(epsilon_eq(dbl, t->data[2][0], expected->data[2][0], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[2][1], expected->data[2][1], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[2][2], expected->data[2][2], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[2][3], expected->data[2][3], EPSILON_TEST));

	cr_expect(epsilon_eq(dbl, t->data[3][0], expected->data[3][0], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[3][1], expected->data[3][1], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[3][2], expected->data[3][2], EPSILON_TEST));
	cr_expect(epsilon_eq(dbl, t->data[3][3], expected->data[3][3], EPSILON_TEST));
}

Test(view_transform, default_orientation)
{
	t_vec3	from = {.x = 0, .y = 0, .z = 0};
	t_vec3	to = {.x = 0, .y = 0, .z = -1};
	t_vec3	up = {.x = 0, .y = 1, .z = 0};
	t_matrix	*t;
	t_matrix	*expected;

	t = view_transform(&from, &to, &up);
	expected = matrix_new_identity(4);
	compare_matrices(t, expected);
	matrix_free(t);
	matrix_free(expected);
}

Test(view_transform, positive_z_direction)
{
	t_vec3	from = {.x = 0, .y = 0, .z = 0};
	t_vec3	to = {.x = 0, .y = 0, .z = 1};
	t_vec3	up = {.x = 0, .y = 1, .z = 0};
	t_matrix	*t;
	t_matrix	*expected;

	t = view_transform(&from, &to, &up);
	expected = matrix_scaling(&(t_vec3){.x = -1, .y = 1, .z = -1});
	compare_matrices(t, expected);
	matrix_free(t);
	matrix_free(expected);
}

Test(view_transform, transform_moves_world)
{
	t_vec3	from = {.x = 0, .y = 0, .z = 8};
	t_vec3	to = {.x = 0, .y = 0, .z = 0};
	t_vec3	up = {.x = 0, .y = 1, .z = 0};
	t_matrix	*t;
	t_matrix	*expected;

	t = view_transform(&from, &to, &up);
	expected = matrix_translation(&(t_vec3){.x = 0, .y = 0, .z = -8});
	compare_matrices(t, expected);
	matrix_free(t);
	matrix_free(expected);
}

Test(view_transform, arbitrary_transform)
{
	t_vec3	from = {.x = 1, .y = 3, .z = 2};
	t_vec3	to = {.x = 4, .y = -2, .z = 8};
	t_vec3	up = {.x = 1, .y = 1, .z = 0};
	t_matrix	*t;
	t_matrix	*expected;

	t = view_transform(&from, &to, &up);
	expected = matrix_new(4, 4);

	expected->data[0][0] = -0.50709;
	expected->data[0][1] = 0.50709;
	expected->data[0][2] = 0.67612;
	expected->data[0][3] = -2.36643;

	expected->data[1][0] = 0.76772;
	expected->data[1][1] = 0.60609;
	expected->data[1][2] = 0.12122;
	expected->data[1][3] = -2.82843;

	expected->data[2][0] = -0.35857;
	expected->data[2][1] = 0.59761;
	expected->data[2][2] = -0.71714;
	expected->data[2][3] = 0.00000;

	expected->data[3][0] = 0.00000;
	expected->data[3][1] = 0.00000;
	expected->data[3][2] = 0.00000;
	expected->data[3][3] = 1.00000;

	compare_matrices(t, expected);
	matrix_free(t);
	matrix_free(expected);
}
