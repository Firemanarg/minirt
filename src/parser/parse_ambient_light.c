/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:10 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 06:41:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_err	lex_checker(t_parser_obj *obj);
static void		cast_fields(t_parser_obj *obj);
static t_err	validate_fields(t_parser_obj *obj);

int	parse_ambient_light(t_parser_obj *obj)
{
	t_ambient_light	*light;

	light = malloc(sizeof(t_ambient_light));
	obj->obj = light;
	light->type = AMBIENT_LIGHT;
	obj->parser->amb_light_count += 1;
	obj->status = OK;
	if (lex_checker(obj) != OK)
		return (1);
	cast_fields(obj);
	if (validate_fields(obj) != OK)
		return (1);
	return (0);
}

static t_err	lex_checker(t_parser_obj *obj)
{
	if (obj->fields_count != AMBIENT_LIGHT_FIELDS_COUNT)
		obj->status = INVALID_ARG_COUNT;
	else if (!ft_str_isdouble(obj->fields[1]))
		obj->status = INVALID_ARG;
	else if (!is_str_vec3(obj->fields[2]))
		obj->status = INVALID_VEC3;
	return (obj->status);
}

static void	cast_fields(t_parser_obj *obj)
{
	t_ambient_light	*light;

	light = (t_ambient_light *) obj->obj;
	light->ratio = ft_atod(obj->fields[1]);
	obj->status = str_to_vec3(obj->fields[2], &light->color);
	light->color.r = light->color.r * light->ratio / 255.0;
	light->color.g = light->color.g * light->ratio / 255.0;
	light->color.b = light->color.b * light->ratio / 255.0;
}

static t_err	validate_fields(t_parser_obj *obj)
{
	t_ambient_light	*light;

	light = (t_ambient_light *) obj->obj;
	if (!is_valid_color(&light->color))
		obj->status = INVALID_COLOR;
	else if (!is_valid_ratio(light->ratio))
		obj->status = INVALID_RATIO;
	return (obj->status);
}
