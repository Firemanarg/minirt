/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vec3_multiply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 01:28:25 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/19 02:22:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>
#include <vec3.h>

void	matrix_vec3_multiply(t_matrix *matrix, t_vec3 *v, t_vec3 *result)
{
	double	**m;

	m = matrix->data;
	result->x = m[0][0] * v->x + m[0][1] * v->y + m[0][2] * v->z + m[0][3];
	result->y = m[1][0] * v->x + m[1][1] * v->y + m[1][2] * v->z + m[1][3];
	result->z = m[2][0] * v->x + m[2][1] * v->y + m[2][2] * v->z + m[2][3];
}
