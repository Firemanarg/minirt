/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate_translate_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:55:05 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:45:29 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_bonus.h"

t_matrix	*matrix_rotate_translate(t_vec3 *v1, t_vec3 *v2, t_vec3 *tr)
{
	t_vec3		axis;
	double		cos_a;
	double		k;
	t_matrix	*m;

	cross(v1, v2, &axis);
	cos_a = dot(v1, v2);
	k = 1.0f / (1.0f + cos_a);
	m = matrix_new(4, 4);
	m->data[0][0] = (axis.x * axis.x * k) + cos_a;
	m->data[0][1] = (axis.y * axis.x * k) - axis.z;
	m->data[0][2] = (axis.z * axis.x * k) + axis.y;
	m->data[0][3] = tr->x;
	m->data[1][0] = (axis.x * axis.y * k) + axis.z;
	m->data[1][1] = (axis.y * axis.y * k) + cos_a;
	m->data[1][2] = (axis.z * axis.y * k) - axis.x;
	m->data[1][3] = tr->y;
	m->data[2][0] = (axis.x * axis.z * k) - axis.y;
	m->data[2][1] = (axis.y * axis.z * k) + axis.x;
	m->data[2][2] = (axis.z * axis.z * k) + cos_a;
	m->data[2][3] = tr->z;
	m->data[3][3] = 1;
	return (m);
}
