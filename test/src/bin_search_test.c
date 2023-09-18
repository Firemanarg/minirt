/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_search_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 02:06:29 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/17 03:32:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

Test(bin_search, find_positive_sym_neg_zero_pos_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -5.0, NULL);
	insert_into_array(r, -3.0, NULL);
	insert_into_array(r, -1.5, NULL);
	insert_into_array(r, 0.0, NULL);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 5.0, NULL);
	insert_into_array(r, 20.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 4));
	free_array(r);
}

Test(bin_search, find_positive_asym_neg_zero_pos_array_1) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -5.0, NULL);
	insert_into_array(r, -3.0, NULL);
	insert_into_array(r, -1.5, NULL);
	insert_into_array(r, 0.0, NULL);
	insert_into_array(r, 2.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 4));
	free_array(r);
}

Test(bin_search, find_positive_asym_neg_zero_pos_array_2) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -1.5, NULL);
	insert_into_array(r, 0.0, NULL);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 5.0, NULL);
	insert_into_array(r, 20.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 2));
	free_array(r);
}

Test(bin_search, find_positive_zero_pos_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, 0.0, NULL);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 5.0, NULL);
	insert_into_array(r, 20.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 1));
	free_array(r);
}

Test(bin_search, find_positive_neg_zero_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -5.0, NULL);
	insert_into_array(r, -3.0, NULL);
	insert_into_array(r, -1.5, NULL);
	insert_into_array(r, 0.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, -1));
	free_array(r);
}

Test(bin_search, find_positive_sym_neg_pos_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -5.0, NULL);
	insert_into_array(r, -3.0, NULL);
	insert_into_array(r, -1.5, NULL);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 5.0, NULL);
	insert_into_array(r, 20.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 3));
	free_array(r);
}

Test(bin_search, find_positive_asym_neg_pos_array_1) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -5.0, NULL);
	insert_into_array(r, -3.0, NULL);
	insert_into_array(r, -1.5, NULL);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 5.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 3));
	free_array(r);
}

Test(bin_search, find_positive_asym_neg_pos_array_2) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -1.5, NULL);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 5.0, NULL);
	insert_into_array(r, 20.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 1));
	free_array(r);
}

Test(bin_search, find_positive_neg_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -5.0, NULL);
	insert_into_array(r, -3.0, NULL);
	insert_into_array(r, -1.5, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, -1));
	free_array(r);
}

Test(bin_search, find_positive_pos_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, 2.0, NULL);
	insert_into_array(r, 5.0, NULL);
	insert_into_array(r, 20.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 0));
	free_array(r);
}

Test(bin_search, find_positive_one_neg_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, -5.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, -1));
	free_array(r);
}

Test(bin_search, find_positive_one_zero_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, 0.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, -1));
	free_array(r);
}

Test(bin_search, find_positive_one_pos_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	insert_into_array(r, 1.0, NULL);
	idx = first_positive(r);
	cr_expect(eq(int, idx, 0));
	free_array(r);
}

Test(bin_search, find_positive_empty_array) {
	t_varray	*r;
	int			idx;

	r = new_array(8);
	idx = first_positive(r);
	cr_expect(eq(int, idx, -1));
	free_array(r);
}
