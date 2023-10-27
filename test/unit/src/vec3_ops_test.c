/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_ops_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 05:34:36 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/23 21:25:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

Test(vec3_ops, test_add_tuples) {
	t_vec3	a, b, result;

	set_vec3(3, 2, 1, &a);
	set_vec3(-2, 3, 1, &b);
	add(&a, &b, &result);
	cr_expect(epsilon_eq(dbl, result.x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 5.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 2.0, EPSILON));
}

Test(vec3_ops, test_subtract_tuples) {
	t_vec3	a, b, result;

	set_vec3(3, 2, 5, &a);
	set_vec3(5, 6, 7, &b);
	subtract(&a, &b, &result);
	cr_expect(epsilon_eq(dbl, result.x, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, -4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, -2.0, EPSILON));
}

Test(vec3_ops, test_negate_tuple) {
	t_vec3	a, result;
	set_vec3(1, -2, 3, &a);
	negate(&a, &result);
	cr_expect(epsilon_eq(dbl, result.x, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, -3.0, EPSILON));
}

Test(vec3_ops, test_multiply_tuple) {
	t_vec3	a, result;

	set_vec3(1, -2, 3, &a);
	double s = 3.5;
	multiply(&a, s, &result);
	cr_expect(epsilon_eq(dbl, result.x, 3.5, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, -7.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 10.5, EPSILON));
}

Test(vec3_ops, test_divide_tuple) {
	t_vec3	a, result;

	set_vec3(1, -2, 3, &a);
	double s = 2;
	divide(&a, s, &result);
	cr_expect(epsilon_eq(dbl, result.x, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 1.5, EPSILON));
}

Test(vec3_ops, test_get_tuple_length_1) {
	t_vec3	a;

	set_vec3(1, 0, 0, &a);
	double l = length(&a);
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
}

Test(vec3_ops, test_get_tuple_length_2) {
	t_vec3	a;

	set_vec3(0, 1, 0, &a);
	double l = length(&a);
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
}

Test(vec3_ops, test_get_tuple_length_3) {
	t_vec3	a;

	set_vec3(0, 0, 1, &a);
	double l = length(&a);
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
}

Test(vec3_ops, test_get_tuple_length_4) {
	t_vec3	a;

	set_vec3(1, 2, 3, &a);
	double l = length(&a);
	cr_expect(epsilon_eq(dbl, l, 3.741657386773941, EPSILON));
}

Test(vec3_ops, test_get_tuple_length_5) {
	t_vec3	a;

	set_vec3(-1, -2, 3, &a);
	double l = length(&a);
	cr_expect(epsilon_eq(dbl, l, 3.741657386773941, EPSILON));
}

Test(vec3_ops, test_normalize_tuple) {
	t_vec3	a, result;

	set_vec3(1, 2, 3, &a);
	normalize(&a, &result);
	double l = length(&result);
	cr_expect(epsilon_eq(dbl, result.x, 0,2672612419124244, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 0,5345224838248488, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 0,8017837257372732, EPSILON));
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
}

Test(vec3_ops, test_dot_product_tuples) {
	t_vec3	a, b;

	set_vec3(1, 2, 3, &a);
	set_vec3(2, 3, 4, &b);
	double d = dot(&a, &b);
	cr_expect(epsilon_eq(dbl, d, 20.0, EPSILON));
}

Test(vec3_ops, test_cross_product_tuples) {
	t_vec3	a, b, result;

	set_vec3(1, 2, 3, &a);
	set_vec3(2, 3, 4, &b);
	cross(&a, &b, &result);
	cr_expect(epsilon_eq(dbl, result.x, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, -1.0, EPSILON));
	cross(&b, &a, &result);
	cr_expect(epsilon_eq(dbl, result.x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, -2.0, EPSILON));
}

Test(vec3_ops, test_hadamard_product_tuples) {
	t_vec3	a, b, result;

	set_vec3(3, 2, 1, &a);
	set_vec3(-2, 3, 1, &b);
	hadamard(&a, &b, &result);
	cr_expect(epsilon_eq(dbl, result.x, -6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.y, 6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.z, 1.0, EPSILON));
}

Test(vec3_ops, test_add_tuples_in_place) {
	t_vec3	a, b;

	set_vec3(3, 2, 1, &a);
	set_vec3(-2, 3, 1, &b);
	add(&a, &b, &a);
	cr_expect(epsilon_eq(dbl, a.x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.y, 5.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.z, 2.0, EPSILON));
}

Test(vec3_ops, test_subtract_tuples_in_place) {
	t_vec3	a, b;

	set_vec3(3, 2, 5, &a);
	set_vec3(5, 6, 7, &b);
	subtract(&a, &b, &a);
	cr_expect(epsilon_eq(dbl, a.x, -2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.y, -4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.z, -2.0, EPSILON));
}

Test(vec3_ops, test_negate_tuple_in_place) {
	t_vec3	a;
	set_vec3(1, -2, 3, &a);
	negate(&a, &a);
	cr_expect(epsilon_eq(dbl, a.x, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.y, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.z, -3.0, EPSILON));
}

Test(vec3_ops, test_multiply_tuple_in_place) {
	t_vec3	a;

	set_vec3(1, -2, 3, &a);
	double s = 3.5;
	multiply(&a, s, &a);
	cr_expect(epsilon_eq(dbl, a.x, 3.5, EPSILON));
	cr_expect(epsilon_eq(dbl, a.y, -7.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.z, 10.5, EPSILON));
}

Test(vec3_ops, test_divide_tuple_in_place) {
	t_vec3	a;

	set_vec3(1, -2, 3, &a);
	double s = 2;
	divide(&a, s, &a);
	cr_expect(epsilon_eq(dbl, a.x, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, a.y, -1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.z, 1.5, EPSILON));
}

Test(vec3_ops, test_normalize_tuple_in_place) {
	t_vec3	a;

	set_vec3(1, 2, 3, &a);
	normalize(&a, &a);
	double l = length(&a);
	cr_expect(epsilon_eq(dbl, a.x, 0,2672612419124244, EPSILON));
	cr_expect(epsilon_eq(dbl, a.y, 0,5345224838248488, EPSILON));
	cr_expect(epsilon_eq(dbl, a.z, 0,8017837257372732, EPSILON));
	cr_expect(epsilon_eq(dbl, l, 1.0, EPSILON));
}

Test(vec3_ops, test_hadamard_product_tuples_in_place) {
	t_vec3	a, b;

	set_vec3(3, 2, 1, &a);
	set_vec3(-2, 3, 1, &b);
	hadamard(&a, &b, &a);
	cr_expect(epsilon_eq(dbl, a.x, -6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.y, 6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, a.z, 1.0, EPSILON));
}
