/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:44:05 by marvin            #+#    #+#             */
/*   Updated: 2023/09/09 22:44:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	fill_submatrix(t_matrix *m, t_matrix *sub, int **indexes, int col);

static t_matrix	*matrix_new_1x1(double value)
{
	t_matrix	*m;

	m = matrix_new(1, 1);
	m->data[0][0] = value;
	return (m);
}

t_matrix	*matrix_submatrix(t_matrix *m, int row, int col)
{
	t_matrix	*sub;
	int			i;
	int			x;
	int			*indexes[2];

	if (m->rows == 1 && m->cols == 1)
		return (NULL);
	else if (m->rows == 2 && m->cols == 2)
		return (matrix_new_1x1(m->data[row % 1][col % 1]));
	sub = matrix_new(m->rows - 1, m->cols - 1);
	indexes[0] = &i;
	indexes[1] = &x;
	i = 0;
	x = 0;
	while (i < m->rows)
	{
		if (i != row)
		{
			fill_submatrix(m, sub, indexes, col);
			x += 1;
		}
		i += 1;
	}
	return (sub);
}

static void	fill_submatrix(t_matrix *m, t_matrix *sub, int **indexes, int col)
{
	int	*i;
	int	*x;
	int	j;
	int	y;

	i = indexes[0];
	x = indexes[1];
	j = 0;
	y = 0;
	while (j < m->cols)
	{
		if (j != col)
		{
			sub->data[*x][y] = m->data[*i][j];
			y += 1;
		}
		j += 1;
	}
}
