/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_misc_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 12:25:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void	negate(t_vec3 *a, t_vec3 *minus_a)
{
	minus_a->x = -(a->x);
	minus_a->y = -(a->y);
	minus_a->z = -(a->z);
}

double	length(t_vec3 *t)
{
	return (sqrt(t->x * t->x
			+ t->y * t->y
			+ t->z * t->z));
}

void	normalize(t_vec3 *t, t_vec3 *norm_t)
{
	const double	len = length(t);

	if (dbl_abs(len) > EPSILON)
		divide(t, len, norm_t);
	else
		set_vec3(0.0, 0.0, 0.0, norm_t);
}
