/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:57:36 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 11:45:25 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_bonus.h"

void	matrix_print(t_matrix *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			printf("%f ", m->data[i][j]);
			j += 1;
		}
		printf("\n");
		i += 1;
	}
}
