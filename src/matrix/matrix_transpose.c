/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:38:46 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 12:28:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*matrix_transpose(t_matrix *m)
{
	t_matrix	*res;
	int			i;
	int			j;

	res = matrix_new(m->cols, m->rows);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			res->data[j][i] = m->data[i][j];
			j += 1;
		}
		i += 1;
	}
	return (res);
}
