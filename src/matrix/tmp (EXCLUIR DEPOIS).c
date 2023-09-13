/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:02:36 by marvin            #+#    #+#             */
/*   Updated: 2023/09/09 22:02:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_tuple	*tuple_new(double x, double y, double z, double w)
{
	t_tuple	*t;

	t = malloc(sizeof(t_tuple));
	*t = (t_tuple){x, y, z, w};
	return (t);
}

t_point	*point_new(double x, double y, double z)
{
	return (tuple_new(x, y, z, 1.0));
}

t_vector	*vector_new(double x, double y, double z)
{
	return (tuple_new(x, y, z, 0.0));
}
