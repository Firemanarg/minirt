/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_matrix_ops_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:46:31 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 16:34:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>
#include <minirt_test.h>

Test(matrix_ops, apply_one_scaling)
{
	t_matrix	*m;
	t_matrix_op	mop[2] = {
		{.op = SCALE, .params = {.x = 2.0, .y = 3.0, .z = 4.0}},
		{.op = NOP}};

	m = matrix_new_identity(4);
	m = matrix_apply(m, mop);

	cr_expect(epsilon_eq(dbl, m->data[0][0], 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][1], 3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[2][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][2], 4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][3], 1.0, EPSILON));
}

Test(matrix_ops, apply_one_rotate_x)
{
	t_matrix	*m;
	t_matrix_op	mop[2] = {
		{.op = ROTATE_X, .param = M_PI / 2.0},
		{.op = NOP}};

	m = matrix_new_identity(4);
	m = matrix_apply(m, mop);

	cr_expect(epsilon_eq(dbl, m->data[0][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][2], -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[2][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][1], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][3], 1.0, EPSILON));
}

Test(matrix_ops, apply_one_rotate_y)
{
	t_matrix	*m;
	t_matrix_op	mop[2] = {
		{.op = ROTATE_Y, .param = M_PI / 2.0},
		{.op = NOP}};

	m = matrix_new_identity(4);
	m = matrix_apply(m, mop);

	cr_expect(epsilon_eq(dbl, m->data[0][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][2], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][1], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[2][0], -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][3], 1.0, EPSILON));
}

Test(matrix_ops, apply_one_rotate_z)
{
	t_matrix	*m;
	t_matrix_op	mop[2] = {
		{.op = ROTATE_Z, .param = M_PI / 2.0},
		{.op = NOP}};

	m = matrix_new_identity(4);
	m = matrix_apply(m, mop);

	cr_expect(epsilon_eq(dbl, m->data[0][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][1], -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[1][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[2][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][2], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][3], 1.0, EPSILON));
}

Test(matrix_ops, apply_one_translate)
{
	t_matrix	*m;
	t_matrix_op	mop[2] = {
		{.op = TRANSLATE, .params = {.x = 2.0, .y = 3.0, .z = 4.0}},
		{.op = NOP}};

	m = matrix_new_identity(4);
	m = matrix_apply(m, mop);

	cr_expect(epsilon_eq(dbl, m->data[0][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][3], 2.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][1], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][3], 3.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[2][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][2], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][3], 4.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][3], 1.0, EPSILON));
}

Test(matrix_ops, apply_one_transpose)
{
	t_matrix	*m;
	t_matrix_op	mop[2] = {
		{.op = TRANSPOSE},
		{.op = NOP}};

	m = matrix_new(4, 4);
	m->data[0][0] = 1;
	m->data[0][1] = 1;
	m->data[0][2] = 1;
	m->data[0][3] = 1;
	m = matrix_apply(m, mop);

	cr_expect(epsilon_eq(dbl, m->data[0][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[1][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[2][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[3][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][3], 0.0, EPSILON));
}

Test(matrix_ops, apply_one_inverse)
{
	t_matrix	*m;
	t_matrix_op	mop[2] = {
		{.op = INVERSE},
		{.op = NOP}};

	m = matrix_new(4, 4);
	m->data[0][0] = 1;
	m->data[0][1] = 2;
	m->data[0][2] = 3;
	m->data[0][3] = 4;
	m->data[1][1] = 1;
	m->data[1][2] = 2;
	m->data[1][3] = 3;
	m->data[2][2] = 1;
	m->data[2][3] = 2;
	m->data[3][3] = 1;

	m = matrix_apply(m, mop);

	cr_expect(epsilon_eq(dbl, m->data[0][0], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][1], -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][2], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][3], 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][1], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][2], -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][3], 1.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[2][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][2], 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][3], -2.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][3], 1.0, EPSILON));
}

Test(matrix_ops, apply_scaling_rotates_inverse)
{
	t_matrix	*m;
	t_matrix_op	mop[7] = {
		{.op = SCALE, .params = {.x = 2.0, .y = 3.0, .z = 4.0}},
		{.op = ROTATE_X, .param = M_PI / 2.0},
		{.op = ROTATE_Y, .param = M_PI / 2.0},
		{.op = ROTATE_Z, .param = M_PI / 2.0},
		{.op = TRANSLATE, .params = {.x = 2.0, .y = 3.0, .z = 4.0}},
		{.op = INVERSE},
		{.op = NOP}};

	m = matrix_new_identity(4);
	m = matrix_apply(m, mop);

	cr_expect(epsilon_eq(dbl, m->data[0][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][2], -0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[0][3], 2.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[1][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][1], 0.33333333333333333333, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[1][3], -1.0, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[2][0], 0.25, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[2][3], -0.5, EPSILON));

	cr_expect(epsilon_eq(dbl, m->data[3][0], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][1], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][2], 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, m->data[3][3], 1.0, EPSILON));
}