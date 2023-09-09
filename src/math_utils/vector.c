/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 05:13:49 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/08 23:55:38 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*new_vector(double x, double y, double z)
{
	return (new_tuple(x, y, z, 0.0));
}

t_bool	is_vector(t_tuple *t)
{
	return (dbl_abs(t->w, 0.0) < EPSILON);
}
