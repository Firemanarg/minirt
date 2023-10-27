/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:27:02 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:46:09 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_bonus.h"

void	set_point_light(t_vec3 *pos, t_color *color, t_point_light *light)
{
	light->pos = *pos;
	light->color = *color;
	light->type = LIGHT;
}
