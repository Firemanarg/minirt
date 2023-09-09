/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_add_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/03 03:45:42 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*add(t_tuple *a, t_tuple *b)
{
	return (new_tuple(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w));
}

t_tuple	*subtract(t_tuple *a, t_tuple *b)
{
	return (new_tuple(a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w));
}
