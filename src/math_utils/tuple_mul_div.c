/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_mul_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/08 23:54:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*multiply(double s, t_tuple *a)
{
	return (new_tuple(s * a->x, s * a->y, s * a->z, a->w));
}

t_tuple	*divide(t_tuple *a, double s)
{
	return (new_tuple(a->x / s, a->y / s, a->z / s, a->w));
}
