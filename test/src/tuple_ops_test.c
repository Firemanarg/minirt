/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 05:34:36 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/03 05:46:14 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <endian.h>
#include <minirt_test.h>

Test(tuple_ops, test_add_tuples) {
	t_tuple	*a = new_tuple(3, 2, 1, 1);
	t_tuple	*b = new_tuple(-2, 3, 1, 0);
	t_tuple *result = add(a, b);
	cr_expect(epsilon_eq(dbl, result->x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, 5.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 1.0, EPSILON));
	free(a);
	free(b);
	free(result);
}

Test(tuple_ops, test_subtract_points) {
	t_tuple	*a = new_tuple(3, 2, 5, 1);
	t_tuple	*b = new_tuple(5, 6, 7, 1);
	t_tuple *result = subtract(a, b);
	cr_expect(epsilon_eq(dbl, result->x, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, -4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	free(a);
	free(b);
	free(result);
}

Test(tuple_ops, test_subtract_vectors) {
	t_tuple	*a = new_tuple(3, 2, 5, 0);
	t_tuple	*b = new_tuple(5, 6, 7, 0);
	t_tuple *result = subtract(a, b);
	cr_expect(epsilon_eq(dbl, result->x, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, -4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	free(a);
	free(b);
	free(result);
}

Test(tuple_ops, test_negate_tuple) {
	t_tuple	*a = new_tuple(1, -2, 3, 0);
	t_tuple *result = negate(a);
	cr_expect(epsilon_eq(dbl, result->x, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, -3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	free(a);
	free(result);
}

Test(tuple_ops, test_negate_tuple_in_place) {
	t_tuple	*a = new_tuple(1, -2, 3, 0);
	negate_in_place(a);
	cr_expect(epsilon_eq(dbl, a->x, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a->y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a->z, -3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a->w, 0.0, EPSILON));
	free(a);
}

Test(tuple_ops, test_multiply_tuple) {
	t_tuple	*a = new_tuple(1, -2, 3, 0);
	double s = 3.5;
	t_tuple *result = multiply(s, a);
	cr_expect(epsilon_eq(dbl, result->x, 3.5, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, -7.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, 10.5, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	free(a);
	free(result);
}

Test(tuple_ops, test_multiply_tuple_in_place) {
	t_tuple	*a = new_tuple(1, -2, 3, 0);
	double s = 3.5;
	multiply_in_place(s, a);
	cr_expect(epsilon_eq(dbl, a->x, 3.5, EPSILON));
	cr_expect(epsilon_eq(dbl, a->y, -7.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a->z, 10.5, EPSILON));
	cr_expect(epsilon_eq(dbl, a->w, 0.0, EPSILON));
	free(a);
}

Test(tuple_ops, test_divide_tuple) {
	t_tuple	*a = new_tuple(1, -2, 3, 0);
	double s = 2;
	t_tuple *result = divide(a, s);
	cr_expect(epsilon_eq(dbl, result->x, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, 1.5, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	free(a);
	free(result);
}

Test(tuple_ops, test_divide_tuple_in_place) {
	t_tuple	*a = new_tuple(1, -2, 3, 0);
	double s = 2;
	divide_in_place(a, s);
	cr_expect(epsilon_eq(dbl, a->x, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, a->y, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a->z, 1.5, EPSILON));
	cr_expect(epsilon_eq(dbl, a->w, 0.0, EPSILON));
	free(a);
}

Test(tuple_ops, test_get_tuple_length_1) {
	t_tuple	*a = new_tuple(1, 0, 0, 0);
	double l = length(a);
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
	free(a);
}

Test(tuple_ops, test_get_tuple_length_2) {
	t_tuple	*a = new_tuple(0, 1, 0, 0);
	double l = length(a);
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
	free(a);
}

Test(tuple_ops, test_get_tuple_length_3) {
	t_tuple	*a = new_tuple(0, 0, 1, 0);
	double l = length(a);
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
	free(a);
}

Test(tuple_ops, test_get_tuple_length_4) {
	t_tuple	*a = new_tuple(1, 2, 3, 0);
	double l = length(a);
	cr_expect(epsilon_eq(dbl, l, 3.741657386773941, EPSILON));
	free(a);
}

Test(tuple_ops, test_get_tuple_length_5) {
	t_tuple	*a = new_tuple(-1, -2, -3, 0);
	double l = length(a);
	cr_expect(epsilon_eq(dbl, l, 3.741657386773941, EPSILON));
	free(a);
}

Test(tuple_ops, test_normalize_tuple) {
	t_tuple	*a = new_tuple(1, 2, 3, 0);
	t_tuple *result = normalize(a);
	double l = length(result);
	cr_expect(epsilon_eq(dbl, result->x, 0,2672612419124244, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, 0,5345224838248488, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, 0,8017837257372732, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
	free(a);
	free(result);
}

Test(tuple_ops, test_normalize_tuple_in_place) {
	t_tuple	*a = new_tuple(1, 2, 3, 0);
	normalize_in_place(a);
	double l = length(a);
	cr_expect(epsilon_eq(dbl, a->x, 0,2672612419124244, EPSILON));
	cr_expect(epsilon_eq(dbl, a->y, 0,5345224838248488, EPSILON));
	cr_expect(epsilon_eq(dbl, a->z, 0,8017837257372732, EPSILON));
	cr_expect(epsilon_eq(dbl, a->w, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
	free(a);
}

Test(tuple_ops, test_dot_product_tuples) {
	t_tuple	*a = new_tuple(1, 2, 3, 0);
	t_tuple	*b = new_tuple(2, 3, 4, 0);
	double d = dot(a, b);
	cr_expect(epsilon_eq(dbl, d, 20.0, EPSILON));
	free(a);
	free(b);
}

Test(tuple_ops, test_cross_product_tuples) {
	t_tuple	*a = new_tuple(1, 2, 3, 0);
	t_tuple	*b = new_tuple(2, 3, 4, 0);
	t_tuple *result = cross(a, b);
	cr_expect(epsilon_eq(dbl, result->x, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	free(result);
	result = cross(b, a);
	cr_expect(epsilon_eq(dbl, result->x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	free(a);
	free(b);
	free(result);
}

Test(tuple_ops, test_hadamard_product_tuples) {
	t_tuple	*a = new_tuple(3, 2, 1, 0);
	t_tuple	*b = new_tuple(-2, 3, 1, 0);
	t_tuple *result = hadamard(a, b);
	cr_expect(epsilon_eq(dbl, result->x, -6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->y, 6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->z, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result->w, 0.0, EPSILON));
	free(a);
	free(b);
	free(result);
}

Test(tuple_ops, test_hadamard_product_tuples_in_place) {
	t_tuple	*a = new_tuple(3, 2, 1, 0);
	t_tuple	*b = new_tuple(-2, 3, 1, 0);
	hadamard_in_place(a, b);
	cr_expect(epsilon_eq(dbl, a->x, -6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a->y, 6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a->z, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a->w, 0.0, EPSILON));
	free(a);
	free(b);
}