/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:45:08 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 11:45:40 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_bonus.h"

t_matrix	*matrix_translation(t_vec3 *v)
{
	t_matrix	*res;

	res = matrix_new_identity(4);
	res->data[0][3] = v->x;
	res->data[1][3] = v->y;
	res->data[2][3] = v->z;
	return (res);
}
