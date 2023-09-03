/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:20:29 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/02 06:23:22 by gmachado         ###   ########.fr       */
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
t_bool	is_vector(t_tuple *t);
t_bool	is_point(t_tuple *t);

// double_ops.c
double	dbl_abs(double a, double b);

// point.c
t_tuple	*new_point(double x, double y, double z);

// vector.c
t_tuple	*new_vector(double x, double y, double z);

#endif
