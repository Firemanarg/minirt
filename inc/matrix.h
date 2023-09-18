/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:33:50 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 14:50:31 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdio.h>
# include <math.h>
# include <vec3.h>

/**
 * @brief Matrix structure
 *
 * @param rows Number of rows
 * @param cols Number of columns
 * @param data Matrix data
*/
typedef struct s_matrix
{
	int		rows;
	int		cols;
	double	**data;
}			t_matrix;

typedef enum e_matrix_opcode
{
	NOP,
	INVERSE,
	TRANSPOSE,
	ROTATE_X,
	ROTATE_Y,
	ROTATE_Z,
	TRANSLATE,
	SCALE
}	t_matrix_opcode;

typedef struct s_matrix_op
{
	t_matrix_opcode	op;
	union
	{
		t_vec3	params;
		double	param;
	};
}	t_matrix_op;

t_matrix	*matrix_multiply(t_matrix *m, t_matrix *b);
t_matrix	*matrix_new(int rows, int cols);
t_matrix	*matrix_new_identity(int size);
void		matrix_free(t_matrix *m);
void		matrix_print(t_matrix *m);
t_matrix	*matrix_submatrix(t_matrix *m, int row, int col);
t_matrix	*matrix_transpose(t_matrix *m);
t_matrix	*matrix_inverse(t_matrix *m);
t_matrix	*matrix_translation(t_vec3 *v);
t_matrix	*matrix_scaling(t_vec3 *v);
t_matrix	*matrix_rotate_x(double rad);
t_matrix	*matrix_rotate_y(double rad);
t_matrix	*matrix_rotate_z(double rad);
double		matrix_determinant(t_matrix *m);
double		matrix_determinant_2x2(t_matrix *m);
double		matrix_minor(t_matrix *m, int row, int col);
double		matrix_cofactor(t_matrix *m, int row, int col);
t_matrix	*matrix_apply(t_matrix *m, t_matrix_op *operations);
// t_matrix	*mtx_shear(t_matrix *m, t_vec3 x, t_vec3 y);

#endif
