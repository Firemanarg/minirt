/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:33:46 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/15 19:23:10 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_matrix	*get_operation_matrix(t_matrix *m, t_matrix_op *operation)
{
	if (operation->op == INVERSE)
		return (matrix_inverse(m));
	if (operation->op == TRANSPOSE)
		return (matrix_transpose(m));
	if (operation->op == ROTATE_X)
		return (matrix_rotate_x(operation->param));
	if (operation->op == ROTATE_Y)
		return (matrix_rotate_y(operation->param));
	if (operation->op == ROTATE_Z)
		return (matrix_rotate_z(operation->param));
	if (operation->op == ROTATE_VEC)
		return (matrix_rotate_to_vec(&operation->params));
	if (operation->op == TRANSLATE)
		return (matrix_translation(&operation->params));
	if (operation->op == SCALE)
		return (matrix_scaling(&operation->params));
	return (matrix_new_identity(4));
}

t_matrix	*matrix_apply(t_matrix *m, t_matrix_op *operations)
{
	t_matrix	*op_matrix;
	t_matrix	*result;

	while (operations->op != NOP)
	{
		if (operations->op == TRANSPOSE || operations->op == INVERSE)
			result = get_operation_matrix(m, operations++);
		else
		{
			op_matrix = get_operation_matrix(m, operations++);
			result = matrix_multiply(op_matrix, m);
			matrix_free(op_matrix);
		}
		matrix_free(m);
		m = result;
	}
	return (m);
}
