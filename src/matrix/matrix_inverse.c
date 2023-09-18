/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:51:07 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 02:00:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*matrix_inverse(t_matrix *m)
{
	t_matrix	*inverse;
	double		det;
	int			row;
	int			col;

	det = matrix_determinant(m);
	if (det == 0)
		return (NULL);
	inverse = matrix_new(m->rows, m->cols);
	row = 0;
	while (row < m->rows)
	{
		col = 0;
		while (col < m->cols)
		{
			inverse->data[col][row] = matrix_cofactor(m, row, col) / det;
			col += 1;
		}
		row += 1;
	}
	return (inverse);
}
