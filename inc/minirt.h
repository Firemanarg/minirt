/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:20:29 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/08 23:57:41 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <math.h>

# define EPSILON 0.00001

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// tuple.c
t_tuple	*new_tuple(double x, double y, double z, double w);

// double_ops.c
double	dbl_abs(double a, double b);

// color.c
t_tuple	*new_color(double red, double green, double blue);
void	clip(t_tuple *color);

// point.c
t_tuple	*new_point(double x, double y, double z);
t_bool	is_point(t_tuple *t);

// tuple_add_sub.c
t_tuple	*add(t_tuple *a, t_tuple *b);
t_tuple	*subtract(t_tuple *a, t_tuple *b);

// tuple_products.c
double	dot(t_tuple *a, t_tuple *b);
t_tuple	*cross(t_tuple *a, t_tuple *b);
t_tuple	*hadamard(t_tuple *a, t_tuple *b);

// tuple_misc_ops.c
t_tuple	*negate(t_tuple *a);
double	length(t_tuple *t);
t_tuple	*normalize(t_tuple *t);

// tuple_mul_div.c
t_tuple	*multiply(double s, t_tuple *a);
t_tuple	*divide(t_tuple *a, double s);

// vector.c
t_tuple	*new_vector(double x, double y, double z);
t_bool	is_vector(t_tuple *t);

#endif
