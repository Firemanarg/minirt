/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_products_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:49:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_bonus.h"

double	dot(t_vec3 *a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void	cross(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	c->x = a->y * b->z - a->z * b->y;
	c->y = a->z * b->x - a->x * b->z;
	c->z = a->x * b->y - a->y * b->x;
}

void	hadamard(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	c->x = a->x * b->x;
	c->y = a->y * b->y;
	c->z = a->z * b->z;
}
