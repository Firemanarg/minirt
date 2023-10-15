/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 06:35:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_valid(t_point_light *light);

t_err	parse_light(char **fields, int fields_count, t_point_light *light)
{
	t_err	err;

	if (fields_count != LIGHT_FIELDS_COUNT)
		return (INVALID_ARG);
	if (light == NULL)
		return (INVALID_ARG);
	light->type = LIGHT;
	err = str_to_vec3(fields[1], &light->pos);
	light->ratio = ft_atod(fields[2]);
	err |= str_to_vec3(fields[3], &light->color);
	err |= !is_valid(light);
	if (err != OK)
		return (INVALID_ARG);
	light->color.r = light->color.r * light->ratio / 255.0;
	light->color.g = light->color.g * light->ratio / 255.0;
	light->color.b = light->color.b * light->ratio / 255.0;
	return (OK);
}

static int	is_valid(t_point_light *light)
{
	if (!is_valid_ratio(light->ratio))
		return (0);
	else if (!is_valid_color(&light->color))
		return (0);
	return (1);
}
