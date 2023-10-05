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

t_base_obj	*parse_ambient_light(char **fields, int fields_count)
{
	t_ambient_light	*light;

	if (fields_count != AMBIENT_LIGHT_FIELDS_COUNT)
		return (NULL);
	light = malloc(sizeof(t_ambient_light));
	if (!light)
		return (NULL);
	light->base.type = AMBIENT_LIGHT;
	light->base.color = parse_color(fields[1]);
	light->base.brightness = parse_double(fields[2]);
	return ((t_base_obj *)light);
}
