/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vec3_multiply_test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 01:53:44 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/19 14:44:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vec3.h"
#include <minirt_test.h>

Test(matrix_vec3_multiply, translate_vector)
{
	t_vec3		v = {.x = 5, .y = -3, .z = 2};
	t_vec3		p = {.x = -3, .y = 4, .z = 5};
	t_vec3		result;
	t_matrix	*t = matrix_translation(&v);

	matrix_vector_multiply(t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 5.0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, translate_inverse_vector)
{
	t_vec3		v = {.x = 5, .y = -3, .z = 2};
	t_vec3		p = {.x = -3, .y = 4, .z = 5};
	t_vec3		result;
	t_matrix	*t = matrix_translation(&v);
	t_matrix	*inv_t = matrix_inverse(t);

	matrix_vector_multiply(inv_t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 5.0, EPSILON));
	matrix_free(t);
	matrix_free(inv_t);
}

Test(matrix_vec3_multiply, scale_vector)
{
	t_vec3		v = {.x = 2, .y = 3, .z = 4};
	t_vec3		p = {.x = -4, .y = 6, .z = 8};
	t_vec3		result;
	t_matrix	*t = matrix_scaling(&v);

	matrix_vector_multiply(t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -8.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 18.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 32.0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, scale_inverse_vector)
{
	t_vec3		v = {.x = 2, .y = 3, .z = 4};
	t_vec3		p = {.x = -4, .y = 6, .z = 8};
	t_vec3		result;
	t_matrix	*t = matrix_scaling(&v);
	t_matrix	*inv_t = matrix_inverse(t);

	matrix_vector_multiply(inv_t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 2.0, EPSILON));
	matrix_free(t);
	matrix_free(inv_t);
}

Test(matrix_vec3_multiply, reflect_vector)
{
	t_vec3		v = {.x = -1, .y = 1, .z = 1};
	t_vec3		p = {.x = 2, .y = 3, .z = 4};
	t_vec3		result;
	t_matrix	*t = matrix_scaling(&v);

	matrix_vector_multiply(t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 4.0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, rotate_x_vector)
{
	t_vec3		p = {.x = 0, .y = 1, .z = 0};
	t_vec3		result_45deg;
	t_vec3		result_90deg;
	t_matrix	*t = matrix_rotate_x(M_PI_4);

	matrix_vector_multiply(t, &p, &result_45deg);
	matrix_free(t);
	t = matrix_rotate_x(M_PI_2);
	matrix_vector_multiply(t, &p, &result_90deg);

	cr_expect(epsilon_eq(dbl, result_45deg.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.y, M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.z, M_SQRT2 / 2, EPSILON));

	cr_expect(epsilon_eq(dbl, result_90deg.x, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.y, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.z, 1, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, rotate_x_inverse_vector)
{
	t_vec3		p = {.x = 0, .y = 1, .z = 0};
	t_vec3		result_315deg;
	t_vec3		result_270deg;
	t_matrix	*t = matrix_rotate_x(M_PI_4);
	t_matrix	*inv_t = matrix_inverse(t);

	matrix_vector_multiply(inv_t, &p, &result_315deg);
	matrix_free(t);
	matrix_free(inv_t);
	t = matrix_rotate_x(M_PI_2);
	inv_t = matrix_inverse(t);
	matrix_vector_multiply(inv_t, &p, &result_270deg);

	cr_expect(epsilon_eq(dbl, result_315deg.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_315deg.y, M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_315deg.z, -M_SQRT2 / 2, EPSILON));

	cr_expect(epsilon_eq(dbl, result_270deg.x, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_270deg.y, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_270deg.z, -1, EPSILON));
	matrix_free(t);
	matrix_free(inv_t);
}

Test(matrix_vec3_multiply, rotate_y_vector)
{
	t_vec3		p = {.x = 0, .y = 0, .z = 1};
	t_vec3		result_45deg;
	t_vec3		result_90deg;
	t_matrix	*t = matrix_rotate_y(M_PI_4);

	matrix_vector_multiply(t, &p, &result_45deg);
	matrix_free(t);
	t = matrix_rotate_y(M_PI_2);
	matrix_vector_multiply(t, &p, &result_90deg);

	cr_expect(epsilon_eq(dbl, result_45deg.x, M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.z, M_SQRT2 / 2, EPSILON));

	cr_expect(epsilon_eq(dbl, result_90deg.x, 1, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.y, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.z, 0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, rotate_z_vector)
{
	t_vec3		p = {.x = 0, .y = 1, .z = 0};
	t_vec3		result_45deg;
	t_vec3		result_90deg;
	t_matrix	*t = matrix_rotate_z(M_PI_4);

	matrix_vector_multiply(t, &p, &result_45deg);
	matrix_free(t);
	t = matrix_rotate_z(M_PI_2);
	matrix_vector_multiply(t, &p, &result_90deg);

	cr_expect(epsilon_eq(dbl, result_45deg.x, -M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.y, M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.z, 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, result_90deg.x, -1, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.z, 0.0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, translate_point)
{
	t_vec3		v = {.x = 5, .y = -3, .z = 2};
	t_vec3		p = {.x = -3, .y = 4, .z = 5};
	t_vec3		result;
	t_matrix	*t = matrix_translation(&v);

	matrix_point_multiply(t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 7.0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, translate_inverse_point)
{
	t_vec3		v = {.x = 5, .y = -3, .z = 2};
	t_vec3		p = {.x = -3, .y = 4, .z = 5};
	t_vec3		result;
	t_matrix	*t = matrix_translation(&v);
	t_matrix	*inv_t = matrix_inverse(t);

	matrix_point_multiply(inv_t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -8.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 7.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 3.0, EPSILON));
	matrix_free(t);
	matrix_free(inv_t);
}

Test(matrix_vec3_multiply, scale_point)
{
	t_vec3		v = {.x = 2, .y = 3, .z = 4};
	t_vec3		p = {.x = -4, .y = 6, .z = 8};
	t_vec3		result;
	t_matrix	*t = matrix_scaling(&v);

	matrix_point_multiply(t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -8.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 18.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 32.0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, scale_inverse_point)
{
	t_vec3		v = {.x = 2, .y = 3, .z = 4};
	t_vec3		p = {.x = -4, .y = 6, .z = 8};
	t_vec3		result;
	t_matrix	*t = matrix_scaling(&v);
	t_matrix	*inv_t = matrix_inverse(t);

	matrix_point_multiply(inv_t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 2.0, EPSILON));
	matrix_free(t);
	matrix_free(inv_t);
}

Test(matrix_vec3_multiply, reflect_point)
{
	t_vec3		v = {.x = -1, .y = 1, .z = 1};
	t_vec3		p = {.x = 2, .y = 3, .z = 4};
	t_vec3		result;
	t_matrix	*t = matrix_scaling(&v);

	matrix_point_multiply(t, &p, &result);
	cr_expect(epsilon_eq(dbl, result.x, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 4.0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, rotate_x_point)
{
	t_vec3		p = {.x = 0, .y = 1, .z = 0};
	t_vec3		result_45deg;
	t_vec3		result_90deg;
	t_matrix	*t = matrix_rotate_x(M_PI_4);

	matrix_point_multiply(t, &p, &result_45deg);
	matrix_free(t);
	t = matrix_rotate_x(M_PI_2);
	matrix_point_multiply(t, &p, &result_90deg);

	cr_expect(epsilon_eq(dbl, result_45deg.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.y, M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.z, M_SQRT2 / 2, EPSILON));

	cr_expect(epsilon_eq(dbl, result_90deg.x, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.y, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.z, 1, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, rotate_x_inverse_point)
{
	t_vec3		p = {.x = 0, .y = 1, .z = 0};
	t_vec3		result_315deg;
	t_vec3		result_270deg;
	t_matrix	*t = matrix_rotate_x(M_PI_4);
	t_matrix	*inv_t = matrix_inverse(t);

	matrix_point_multiply(inv_t, &p, &result_315deg);
	matrix_free(t);
	matrix_free(inv_t);
	t = matrix_rotate_x(M_PI_2);
	inv_t = matrix_inverse(t);
	matrix_point_multiply(inv_t, &p, &result_270deg);

	cr_expect(epsilon_eq(dbl, result_315deg.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_315deg.y, M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_315deg.z, -M_SQRT2 / 2, EPSILON));

	cr_expect(epsilon_eq(dbl, result_270deg.x, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_270deg.y, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_270deg.z, -1, EPSILON));
	matrix_free(t);
	matrix_free(inv_t);
}

Test(matrix_vec3_multiply, rotate_y_point)
{
	t_vec3		p = {.x = 0, .y = 0, .z = 1};
	t_vec3		result_45deg;
	t_vec3		result_90deg;
	t_matrix	*t = matrix_rotate_y(M_PI_4);

	matrix_point_multiply(t, &p, &result_45deg);
	matrix_free(t);
	t = matrix_rotate_y(M_PI_2);
	matrix_point_multiply(t, &p, &result_90deg);

	cr_expect(epsilon_eq(dbl, result_45deg.x, M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.z, M_SQRT2 / 2, EPSILON));

	cr_expect(epsilon_eq(dbl, result_90deg.x, 1, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.y, 0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.z, 0, EPSILON));
	matrix_free(t);
}

Test(matrix_vec3_multiply, rotate_z_point)
{
	t_vec3		p = {.x = 0, .y = 1, .z = 0};
	t_vec3		result_45deg;
	t_vec3		result_90deg;
	t_matrix	*t = matrix_rotate_z(M_PI_4);

	matrix_point_multiply(t, &p, &result_45deg);
	matrix_free(t);
	t = matrix_rotate_z(M_PI_2);
	matrix_point_multiply(t, &p, &result_90deg);

	cr_expect(epsilon_eq(dbl, result_45deg.x, -M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.y, M_SQRT2 / 2, EPSILON));
	cr_expect(epsilon_eq(dbl, result_45deg.z, 0.0, EPSILON));

	cr_expect(epsilon_eq(dbl, result_90deg.x, -1, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result_90deg.z, 0.0, EPSILON));
	matrix_free(t);
}
