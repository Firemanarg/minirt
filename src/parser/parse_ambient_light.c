/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:10 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/02 13:41:10 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_valid(t_ambient_light *light);

t_ambient_light	*parse_ambient_light(char **fields, int fields_count)
{
	t_ambient_light	*light;
	t_err			err;

	if (fields_count != AMBIENT_LIGHT_FIELDS_COUNT)
		return (NULL);
	light = malloc(sizeof(t_ambient_light));
	if (!light)
		return (NULL);
	light->type = AMBIENT_LIGHT;
	light->ratio = ft_atod(fields[1]);
	err = str_to_vec3(fields[2], &light->color);
	if (err != OK || !is_valid(light))
	{
		free(light);
		return (NULL);
	}
	return (light);
}

static int	is_valid(t_ambient_light *light)
{
	if (!is_valid_color(&light->color))
		return (0);
	if (!is_valid_ratio(light->ratio))
		return (0);
	return (1);
}
