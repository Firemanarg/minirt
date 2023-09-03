/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_misc_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/03 00:58:07 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*negate(t_tuple *a)
{
	return (new_tuple(-(a->x), -(a->y), -(a->z), a->w));
}

void	negate_in_place(t_tuple *t, double x, double y, double z)
{
	t->x = -x;
	t->y = -y;
	t->z = -z;
}

double	length(t_tuple *t)
{
	return (sqrt(t->x * t->x + t->y * t->y + t->z * t->z));
}

t_tuple	*normalize(t_tuple *t)
{
	const double	len = length(t);

	if (len != 0)
		return (new_tuple(t->x / len, t->y / len, t->z / len, t->w));
	return (new_tuple(0.0, 0.0, 0.0, t->w));
}

void	normalize_in_place(t_tuple *t)
{
	const double	len = length(t);

	if (len != 0)
	{
		t->x /= len;
		t->y /= len;
		t->z /= len;
	}
}
