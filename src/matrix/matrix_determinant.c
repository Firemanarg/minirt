/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:34:32 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 02:00:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

double	matrix_determinant(t_matrix *m)
{
	int			col;
	double		det;

	det = 0;
	if (m->rows == 2 && m->cols == 2)
		return (matrix_determinant_2x2(m));
	else
	{
		col = 0;
		while (col < m->cols)
		{
			det += m->data[0][col] * matrix_cofactor(m, 0, col);
			col += 1;
		}
	}
	return (det);
}

double	matrix_determinant_2x2(t_matrix *m)
{
	double	det;

	if (m->rows != 2 || m->cols != 2)
		return (0);
	det = m->data[0][0] * m->data[1][1] - m->data[0][1] * m->data[1][0];
	return (det);
}
