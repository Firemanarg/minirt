/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:41:21 by marvin            #+#    #+#             */
/*   Updated: 2023/09/11 10:41:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix_minor(t_matrix *m, int row, int col)
{
	t_matrix	*sub;
	double		minor;

	sub = matrix_submatrix(m, row, col);
	minor = matrix_determinant(sub);
	matrix_free(sub);
	return (minor);
}
