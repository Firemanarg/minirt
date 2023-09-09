/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 05:13:49 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/08 23:56:00 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*new_point(double x, double y, double z)
{
	return (new_tuple(x, y, z, 1.0));
}

t_bool	is_point(t_tuple *t)
{
	return (dbl_abs(t->w, 1.0) < EPSILON);
}
