/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_products.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/08 23:54:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	dot(t_tuple *a, t_tuple *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_tuple	*cross(t_tuple *a, t_tuple *b)
{
	return (new_tuple(a->y * b->z - a->z * b->y,
			a->z * b->x - a->x * b->z,
			a->x * b->y - a->y * b->x, 0.0));
}

t_tuple	*hadamard(t_tuple *a, t_tuple *b)
{
	return (new_tuple(a->x * b->x,
			a->y * b->y,
			a->z * b->z,
			0.0));
}
