/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:53:28 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/15 18:54:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	dbl_abs(double a)
{
	if (a >= 0.0)
		return (a);
	return (-a);
}

double	dbl_equal(double a, double b)
{
	return (dbl_abs(a - b) < EPSILON);
}
