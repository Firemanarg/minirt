/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:17:47 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 20:43:02 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*matrix_rotate_x(double rad)
{
	t_matrix	*res;

	res = matrix_new(4, 4);
	res->data[0][0] = 1;
	res->data[1][1] = cos(rad);
	res->data[1][2] = -sin(rad);
	res->data[2][1] = sin(rad);
	res->data[2][2] = cos(rad);
	res->data[3][3] = 1;
	return (res);
}

t_matrix	*matrix_rotate_y(double rad)
{
	t_matrix	*res;

	res = matrix_new(4, 4);
	res->data[0][0] = cos(rad);
	res->data[0][2] = sin(rad);
	res->data[1][1] = 1;
	res->data[2][0] = -sin(rad);
	res->data[2][2] = cos(rad);
	res->data[3][3] = 1;
	return (res);
}

t_matrix	*matrix_rotate_z(double rad)
{
	t_matrix	*res;

	res = matrix_new(4, 4);
	res->data[0][0] = cos(rad);
	res->data[0][1] = -sin(rad);
	res->data[1][0] = sin(rad);
	res->data[1][1] = cos(rad);
	res->data[2][2] = 1;
	res->data[3][3] = 1;
	return (res);
}

t_matrix	*matrix_rotate_to_vec(t_vec3 *to)
{
	t_vec3		axis;
	t_vec3		from;
	double		cos_a;
	double		k;
	t_matrix	*m;

	set_vec3(0.0, 1.0, 0.0, &from);
	if (equal(to, &from))
		return (matrix_new_identity(4));
	cross(&from, to, &axis);
	cos_a = dot(&from, to);
	k = 1.0 / (1.0 + cos_a);
	m = matrix_new(4, 4);
	m->data[0][0] = (axis.x * axis.x * k) + cos_a;
	m->data[0][1] = (axis.y * axis.x * k) - axis.z;
	m->data[0][2] = (axis.z * axis.x * k) + axis.y;
	m->data[1][0] = (axis.x * axis.y * k) + axis.z;
	m->data[1][1] = (axis.y * axis.y * k) + cos_a;
	m->data[1][2] = (axis.z * axis.y * k) - axis.x;
	m->data[2][0] = (axis.x * axis.z * k) - axis.y;
	m->data[2][1] = (axis.y * axis.z * k) + axis.x;
	m->data[2][2] = (axis.z * axis.z * k) + cos_a;
	m->data[3][3] = 1.0;
	return (m);
}

