/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scaling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:10:57 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 02:00:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*matrix_scaling(t_vec3 *v)
{
	t_matrix	*res;

	res = matrix_new(4, 4);
	res->data[0][0] = v->x;
	res->data[1][1] = v->y;
	res->data[2][2] = v->z;
	res->data[3][3] = 1;
	return (res);
}
