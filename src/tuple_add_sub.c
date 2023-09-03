/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_add_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/03 00:55:07 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*add(t_tuple *a, t_tuple *b)
{
	return (new_tuple(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w));
}

void	add_in_place(t_tuple *t, double x, double y, double z, double w)
{
	t->x += x;
	t->y += y;
	t->z += z;
	t->w += w;
}

t_tuple	*subtract(t_tuple *a, t_tuple *b)
{
	return (new_tuple(a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w));
}

void	subtract_in_place(t_tuple *t, double x, double y, double z, double w)
{
	t->x -= x;
	t->y -= y;
	t->z -= z;
	t->w -= w;
}
