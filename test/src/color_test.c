/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 05:34:23 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/03 05:54:29 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

Test(tuple, test_new_color_is_correct_tuple) {
	t_tuple	*c = new_color(1, 0.5, 0);
	cr_expect(epsilon_eq(dbl, c->x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_valid_color) {
	t_tuple	*c = new_color(1, 0.5, 0);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_bright_red_color) {
	t_tuple	*c = new_color(2, 0.5, 0);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_bright_green_color) {
	t_tuple	*c = new_color(0.5, 2, 0);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_bright_blue_color) {
	t_tuple	*c = new_color(0.5, 1, 2);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_bright_white_color) {
	t_tuple	*c = new_color(2, 2, 2);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_dark_red_color) {
	t_tuple	*c = new_color(-0.1, 0.5, 0);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_dark_green_color) {
	t_tuple	*c = new_color(0.5, -0.1, 0);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_dark_blue_color) {
	t_tuple	*c = new_color(0.5, 1, -0.1);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 0.5, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}

Test(tuple, test_clip_dark_black_color) {
	t_tuple	*c = new_color(-0.1, -0.1, -0.1);
	clip(c);
	cr_expect(epsilon_eq(dbl, c->x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->z, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, c->w, 0.0, EPSILON));
	free(c);
}