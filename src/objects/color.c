/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:41:31 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 12:19:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	set_color(double red, double green, double blue, t_color *c)
{
	c->r = red;
	c->g = green;
	c->b = blue;
}
