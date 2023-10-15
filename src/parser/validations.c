/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:58:18 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 07:41:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_valid_color(t_vec3 *color)
{
	if (color->x < 0 || color->x > 255)
		return (0);
	else if (color->y < 0 || color->y > 255)
		return (0);
	else if (color->z < 0 || color->z > 255)
		return (0);
	return (1);
}

int	is_valid_ratio(double ratio)
{
	return (ratio >= MIN_RATIO && ratio <= MAX_RATIO);
}

int	is_valid_fov(double fov)
{
	return (fov >= MIN_FOV && fov <= MAX_FOV);
}

int	is_valid_direction(t_vec3 *dir)
{
	if (dir->x < -1 || dir->x > 1)
		return (0);
	else if (dir->y < -1 || dir->y > 1)
		return (0);
	else if (dir->z < -1 || dir->z > 1)
		return (0);
	else if (dir->x  == 0 && dir->y  == 0 && dir->z == 0)
		return (0);
	return (1);
}
