/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_array_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:21:20 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 02:12:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>
#include <threads.h>

Test(var_array, test_new_array) {
	t_varray	*r;

	r = new_array(8);
	cr_expect(eq(int, r->capacity, 8));
	cr_expect(eq(int, r->length, 0));
	free(r->arr);
	free(r);
}

Test(var_array, test_insert_into_array) {
	t_varray	*r;

	r = new_array(8);
	insert_into_array(r, 1.0, NULL);
	cr_expect(eq(int, r->capacity, 8));
	cr_expect(eq(int, r->length, 1));
	free(r->arr);
	free(r);
}

Test(var_array, test_auto_resize_array) {
	t_varray	*r;

	r = new_array(2);
	insert_into_array(r, 1.0, NULL);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 3.0, NULL);
	cr_expect(eq(int, r->capacity, 4));
	cr_expect(eq(int, r->length, 3));
	cr_expect(epsilon_eq(dbl, ((t_isect *)r->arr)[2].t, 3.0, EPSILON));
	insert_into_array(r, 4.0, NULL);
	insert_into_array(r, 5.0, NULL);
	cr_expect(eq(int, r->capacity, 8));
	cr_expect(eq(int, r->length, 5));
	cr_expect(epsilon_eq(dbl, ((t_isect *)r->arr)[4].t, 5.0, EPSILON));
	free_array(r);
}
