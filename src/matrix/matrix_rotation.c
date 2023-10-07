/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:17:47 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 12:27:49 by gmachado         ###   ########.fr       */
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
