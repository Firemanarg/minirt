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

static t_err	lex_checker(t_parser_obj *obj);
static void		cast_fields(t_parser_obj *obj);
static t_err	validate_fields(t_parser_obj *obj);
static void		apply_transforms(t_point_light *light);

int	parse_light(t_parser_obj *obj)
{
	t_point_light	*light;

	light = malloc(sizeof(t_point_light));
	obj->obj = light;
	light->type = LIGHT;
	obj->parser->light_count += 1;
	obj->status = OK;
	if (lex_checker(obj) != OK)
		return (1);
	cast_fields(obj);
	if (validate_fields(obj) != OK)
		return (1);
	apply_transforms(light);
	print_msg("Parsing", "Parsed light", TXT_COLOR_CYAN);
	return (0);
}

static t_err	lex_checker(t_parser_obj *obj)
{
	if (obj->fields_count != LIGHT_FIELDS_COUNT)
		obj->status = INVALID_ARG_COUNT;
	else if (!is_str_vec3(obj->fields[1]))
		obj->status = INVALID_VEC3;
	else if (!ft_str_isdouble(obj->fields[2]))
		obj->status = INVALID_ARG;
	else if (!is_str_vec3(obj->fields[3]))
		obj->status = INVALID_VEC3;
	return (obj->status);
}

static void	cast_fields(t_parser_obj *obj)
{
	t_point_light	*light;
	t_err			err;

	light = (t_point_light *) obj->obj;
	err = str_to_vec3(obj->fields[1], &light->pos);
	light->ratio = ft_atod(obj->fields[2]);
	err |= str_to_vec3(obj->fields[3], &light->color);
	if (err != OK)
		obj->status = INVALID_VEC3;
}

static t_err	validate_fields(t_parser_obj *obj)
{
	t_point_light	*light;

	light = (t_point_light *) obj->obj;
	if (!is_valid_color(&light->color))
		obj->status = INVALID_COLOR;
	else if (!is_valid_ratio(light->ratio))
		obj->status = INVALID_RATIO;
	return (obj->status);
}

static void	apply_transforms(t_point_light *light)
{
	light->color.r = light->color.r * light->ratio / 255.0;
	light->color.g = light->color.g * light->ratio / 255.0;
	light->color.b = light->color.b * light->ratio / 255.0;
}
