/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:33:50 by marvin            #+#    #+#             */
/*   Updated: 2023/09/08 12:33:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdio.h>
# include <math.h>

# define DEBUG_ON 0																// DEBUG

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

/* External { */
typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_tuple;

typedef t_tuple	t_point;
typedef t_tuple	t_vector;
/* } External */

/* Temporary */
t_tuple		*tuple_new(double x, double y, double z, double w);
t_point		*point_new(double x, double y, double z);
t_vector	*vector_new(double x, double y, double z);
/* Temporary */

t_matrix	*matrix_multiply(t_matrix *m, t_matrix *b);
t_matrix	*matrix_new(int rows, int cols);
t_matrix	*matrix_new_identity(int size);
void		matrix_free(t_matrix *m);
void		matrix_print(t_matrix *m);
t_matrix	*matrix_submatrix(t_matrix *m, int row, int col);
t_matrix	*matrix_transpose(t_matrix *m);
t_matrix	*matrix_inverse(t_matrix *m);
t_matrix	*matrix_translation(t_vector *v);
t_matrix	*matrix_scaling(t_vector *v);
t_matrix	*matrix_rotate_x(double rad);
t_matrix	*matrix_rotate_y(double rad);
t_matrix	*matrix_rotate_z(double rad);
double		matrix_determinant(t_matrix *m);
double		matrix_determinant_2x2(t_matrix *m);
double		matrix_minor(t_matrix *m, int row, int col);
double		matrix_cofactor(t_matrix *m, int row, int col);
// t_matrix	*mtx_shear(t_matrix *m, t_vector x, t_vector y);

#endif