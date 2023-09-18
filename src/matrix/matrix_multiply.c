/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:02:55 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 02:00:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

static void	multiply_loop(t_matrix *res, t_matrix *m1, t_matrix *m2);

t_matrix	*matrix_multiply(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*res;

	if (m1->cols != m2->rows)
		return (NULL);
	res = matrix_new(m1->rows, m2->cols);
	multiply_loop(res, m1, m2);
	return (res);
}

static void	multiply_loop(t_matrix *res, t_matrix *m1, t_matrix *m2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < m1->rows)
	{
		k = 0;
		while (k < m2->cols)
		{
			j = 0;
			while (j < m1->cols)
			{
				(res->data)[i][j] = (res->data)[i][j]
					+ (m1->data)[i][k] * (m2->data)[k][j];
				j += 1;
			}
			k += 1;
		}
		i += 1;
	}
}
