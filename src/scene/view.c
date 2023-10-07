/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:29:32 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 04:00:19 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_matrix	*get_transform_matrix(t_vec3 *true_up,
	t_vec3 *forward, t_vec3 *left, t_vec3 *from)
{
	t_matrix	*orientation;
	t_matrix	*translation;
	t_matrix	*transform;
	t_vec3		minus_from;

	orientation = matrix_new_identity(4);
	orientation->data[0][0] = left->x;
	orientation->data[0][1] = left->y;
	orientation->data[0][2] = left->z;
	orientation->data[1][0] = true_up->x;
	orientation->data[1][1] = true_up->y;
	orientation->data[1][2] = true_up->z;
	orientation->data[2][0] = -forward->x;
	orientation->data[2][1] = -forward->y;
	orientation->data[2][2] = -forward->z;
	negate(from, &minus_from);
	translation = matrix_translation(&minus_from);
	transform = matrix_multiply(orientation, translation);
	matrix_free(orientation);
	matrix_free(translation);
	return (transform);
}

t_matrix	*view_transform(t_vec3 *from, t_vec3 *to, t_vec3 *up)
{
	t_vec3		true_up;
	t_vec3		forward;
	t_vec3		left;

	subtract(to, from, &forward);
	normalize(&forward, &forward);
	normalize(up, &true_up);
	cross(&forward, &true_up, &left);
	cross(&left, &forward, &true_up);
	return (get_transform_matrix(&true_up, &forward, &left, from));
}
