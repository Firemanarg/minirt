/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:59:47 by marvin            #+#    #+#             */
/*   Updated: 2023/09/11 10:59:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix_cofactor(t_matrix *m, int row, int col)
{
	double	cofactor;

	cofactor = matrix_minor(m, row, col);
	if ((row + col) % 2 != 0)
		cofactor *= -1;
	return (cofactor);
}
