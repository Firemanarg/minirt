/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 04:55:49 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/03 05:42:58 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*new_color(double red, double green, double blue)
{
	t_tuple	*color;

	color = malloc(sizeof(*color));
	color->x = red;
	color->y = green;
	color->z = blue;
	color->w = 0.0;
	return (color);
}

void	clip(t_tuple *color)
{
	if (color->x > 1.0)
		color->x = 1.0;
	else if (color->x < 0.0)
		color->x = 0.0;
	if (color->y > 1.0)
		color->y = 1.0;
	else if (color->y < 0.0)
		color->y = 0.0;
	if (color->z > 1.0)
		color->z = 1.0;
	else if (color->z < 0.0)
		color->z = 0.0;
}
