/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:17:40 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 14:27:59 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_BONUS_H
# define VEC3_BONUS_H

# include <stdlib.h>
# include <math.h>
# include "error_bonus.h"
# include "libft_x.h"

# define EPSILON 1e-8

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef union u_vec3
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
	struct
	{
		double	r;
		double	g;
		double	b;
	};
}	t_vec3;

// double_ops.c
double	dbl_abs(double a);
double	dbl_equal(double a, double b);

// vec3.c
void	set_vec3(double x, double y, double z, t_vec3 *t);
t_err	str_to_vec3(const char *str, t_vec3 *vec);

// vec3_add_sub.c
void	add(t_vec3 *a, t_vec3 *b, t_vec3 *c);
void	subtract(t_vec3 *a, t_vec3 *b, t_vec3 *c);

// vec3_misc_ops.c
t_bool	equal(t_vec3 *a, t_vec3 *b);
double	length(t_vec3 *t);
void	negate(t_vec3 *a, t_vec3 *minus_a);
void	normalize(t_vec3 *t, t_vec3 *norm_t);

// vec3_mul_div.c
void	divide(t_vec3 *a, double s, t_vec3 *b);
void	multiply(t_vec3 *a, double s, t_vec3 *b);

// vec3_products.c
void	cross(t_vec3 *a, t_vec3 *b, t_vec3 *c);
double	dot(t_vec3 *a, t_vec3 *b);
void	hadamard(t_vec3 *a, t_vec3 *b, t_vec3 *c);

#endif
