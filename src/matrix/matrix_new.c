/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:41:35 by marvin            #+#    #+#             */
/*   Updated: 2023/09/09 20:41:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*matrix_new(int rows, int cols)
{
	t_matrix	*matrix;
	int			i;
	int			j;

	matrix = malloc(sizeof(t_matrix));
	matrix->rows = rows;
	matrix->cols = cols;
	matrix->data = malloc(sizeof(double *) * rows);
	i = 0;
	while (i < rows)
	{
		matrix->data[i] = malloc(sizeof(double) * cols);
		j = 0;
		while (j < cols)
		{
			matrix->data[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (matrix);
}

t_matrix	*matrix_new_identity(int size)
{
	t_matrix	*matrix;
	int			i;
	int			j;

	matrix = matrix_new(size, size);
	matrix->data[0][0] = 1;
	matrix->data[1][1] = 1;
	matrix->data[2][2] = 1;
	matrix->data[3][3] = 1;
	return (matrix);
}
