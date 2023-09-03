/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:37:49 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/01 04:46:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*new_tuple(double x, double y, double z, double w)
{
	t_tuple	*result;

	result = malloc(sizeof(*result));
	result->x = x;
	result->y = y;
	result->z = z;
	result->w = w;
	return (result);
}

t_bool	is_vector(t_tuple *t)
{
	return (dbl_abs(t->w, 0.0) < EPSILON);
}

t_bool	is_point(t_tuple *t)
{
	return (dbl_abs(t->w, 1.0) < EPSILON);
}