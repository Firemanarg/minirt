/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:17:40 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 23:54:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

# define EPSILON 1e-6

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

// tuple.c
void	set_vec3(double x, double y, double z, t_vec3 *t);

// tuple_add_sub.c
void	add(t_vec3 *a, t_vec3 *b, t_vec3 *c);
void	subtract(t_vec3 *a, t_vec3 *b, t_vec3 *c);

// tuple_products.c
double	dot(t_vec3 *a, t_vec3 *b);
void	cross(t_vec3 *a, t_vec3 *b, t_vec3 *c);
void	hadamard(t_vec3 *a, t_vec3 *b, t_vec3 *c);

// tuple_misc_ops.c
void	negate(t_vec3 *a, t_vec3 *minus_a);
double	length(t_vec3 *t);
void	normalize(t_vec3 *t, t_vec3 *norm_t);

// tuple_mul_div.c
void	multiply(t_vec3 *a, double s, t_vec3 *b);
void	divide(t_vec3 *a, double s, t_vec3 *b);

// double_ops.c
double	dbl_abs(double a);

#endif