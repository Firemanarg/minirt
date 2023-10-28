/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:41:21 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 11:45:10 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_bonus.h"

double	matrix_minor(t_matrix *m, int row, int col)
{
	t_matrix	*sub;
	double		minor;

	sub = matrix_submatrix(m, row, col);
	minor = matrix_determinant(sub);
	matrix_free(sub);
	return (minor);
}
