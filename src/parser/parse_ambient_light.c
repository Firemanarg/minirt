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

t_err	parse_ambient_light(char **fields, int fields_count,
			t_ambient_light *light)
{
	t_err	err;

	if (fields_count != AMBIENT_LIGHT_FIELDS_COUNT)
		return (INVALID_ARG);
	if (light == NULL)
		return (INVALID_ARG);
	light->type = AMBIENT_LIGHT;
	light->ratio = ft_atod(fields[1]);
	err = str_to_vec3(fields[2], &light->color);
	err |= !is_valid(light);
	if (err != OK)
		return (err);
	return (OK);
}

static int	is_valid(t_ambient_light *light)
{
	if (!is_valid_color(&light->color))
		return (0);
	if (!is_valid_ratio(light->ratio))
		return (0);
	return (1);
}
