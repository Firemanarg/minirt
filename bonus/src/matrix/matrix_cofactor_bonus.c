/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:59:47 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 11:44:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_bonus.h"

double	matrix_cofactor(t_matrix *m, int row, int col)
{
	double	cofactor;

	cofactor = matrix_minor(m, row, col);
	if ((row + col) % 2 != 0)
		cofactor *= -1;
	return (cofactor);
}
