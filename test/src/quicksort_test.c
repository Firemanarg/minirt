/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:52:45 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/17 03:33:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_array.h"
#include <minirt_test.h>

Test(quicksort, sort_five_elements) {
	t_varray	*r;

	r = new_array(8);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 1.0, NULL);
	insert_into_array(r, 4.0, NULL);
	insert_into_array(r, 5.0, NULL);
	insert_into_array(r, 3.0, NULL);
	quicksort(r);
	cr_expect(epsilon_eq(dbl, ((t_isect *)r->arr)[0].t, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)r->arr)[1].t, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)r->arr)[2].t, 3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)r->arr)[3].t, 4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, ((t_isect *)r->arr)[4].t, 5.0, EPSILON));
	free_array(r);
}
