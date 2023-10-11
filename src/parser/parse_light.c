/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/02 13:41:35 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_valid(t_point_light *light);

t_point_light	*parse_light(char **fields, int fields_count)
{
	t_point_light	*light;
	t_err		err;

	if (fields_count != LIGHT_FIELDS_COUNT)
		return (NULL);
	light = malloc(sizeof(t_point_light));
	if (!light)
		return (NULL);
	light->type = LIGHT;
	err = str_to_vec3(fields[1], &light->pos);
	light->ratio = ft_atod(fields[2]);
	err |= str_to_vec3(fields[3], &light->color);
	if (err != OK || !is_valid(light))
	{
		free(light);
		return (NULL);
	}
	return (light);
}

static int	is_valid(t_point_light *light)
{
	if (!is_valid_ratio(light->ratio))
		return (0);
	else if (!is_valid_color(&light->color))
		return (0);
	return (1);
}
