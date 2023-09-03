/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_mul_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/03 00:57:26 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*multiply(double s, t_tuple *a)
{
	return (new_tuple(s * a->x, s * a->y, s * a->z, a->w));
}

void	multiply_in_place(double s, t_tuple *t)
{
	t->x *= s;
	t->y *= s;
	t->z *= s;
}

t_tuple	*divide(double s, t_tuple *a)
{
	return (new_tuple(a->x / s, a->y / s, a->z / s, a->w));
}

void	divide_in_place(double s, t_tuple *t)
{
	t->x /= s;
	t->y /= s;
	t->z /= s;
}
