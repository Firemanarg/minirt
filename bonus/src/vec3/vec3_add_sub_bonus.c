/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add_sub_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:48:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:48:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_bonus.h"

void	add(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
}

void	subtract(t_vec3 *a, t_vec3 *b, t_vec3 *c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;
}
