/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:45:08 by marvin            #+#    #+#             */
/*   Updated: 2023/09/09 21:45:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*matrix_translation(t_vector *v)
{
	t_matrix	*res;

	res = matrix_new_identity(4);
	res->data[0][3] = v->x;
	res->data[1][3] = v->y;
	res->data[2][3] = v->z;
	return (res);
}
