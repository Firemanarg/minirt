/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:17:47 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 22:02:42 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_matrix	*set_rotation_values(t_matrix *m, t_vec3 *from, t_vec3 *to);

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
	t_vec3		from;
	t_vec3		minus_from;
	t_matrix	*m;

	set_vec3(0.0, 1.0, 0.0, &from);
	set_vec3(0.0, -1.0, 0.0, &minus_from);
	m = matrix_new_identity(4);
	if (equal(to, &from))
		return (m);
	if (equal(to, &minus_from))
	{
		m->data[0][0] = -1;
		m->data[1][1] = -1;
		return (m);
	}
	return (set_rotation_values(m, &from, to));
}

static t_matrix	*set_rotation_values(t_matrix *m, t_vec3 *from, t_vec3 *to)
{
	t_vec3		axis;
	double		cos_a;
	double		k;

	cross(from, to, &axis);
	cos_a = dot(from, to);
	k = 1.0 / (1.0 + cos_a);
	m->data[0][0] = (axis.x * axis.x * k) + cos_a;
	m->data[0][1] = (axis.y * axis.x * k) - axis.z;
	m->data[0][2] = (axis.z * axis.x * k) + axis.y;
	m->data[1][0] = (axis.x * axis.y * k) + axis.z;
	m->data[1][1] = (axis.y * axis.y * k) + cos_a;
	m->data[1][2] = (axis.z * axis.y * k) - axis.x;
	m->data[2][0] = (axis.x * axis.z * k) - axis.y;
	m->data[2][1] = (axis.y * axis.z * k) + axis.x;
	m->data[2][2] = (axis.z * axis.z * k) + cos_a;
	return (m);
}
