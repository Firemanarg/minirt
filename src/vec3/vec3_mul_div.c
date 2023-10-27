/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 12:25:21 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void	multiply(t_vec3 *a, double s, t_vec3 *b)
{
	b->x = s * a->x;
	b->y = s * a->y;
	b->z = s * a->z;
}

void	divide(t_vec3 *a, double s, t_vec3 *b)
{
	b->x = a->x / s;
	b->y = a->y / s;
	b->z = a->z / s;
}
