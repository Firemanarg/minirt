/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:22 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 21:38:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "graphics.h"
#include "shading.h"

static t_err	lex_checker(t_parser_obj *obj);
static void		cast_fields(t_parser_obj *obj);
static t_err	validate_fields(t_parser_obj *obj);
static void		apply_transforms(t_camera *camera);

/**
 * @brief Checks if the fields are valid for a camera object.
 *
 * @param obj The parser object containing the fields to be checked.
 *
 * @return int 0 if camera has been successfully parsed, 1 otherwise.
 */
int	parse_camera(t_parser_obj *obj)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	obj->obj = camera;
	camera->type = CAMERA;
	obj->parser->camera_count += 1;
	obj->status = OK;
	if (lex_checker(obj) != OK)
		return (1);
	cast_fields(obj);
	if (validate_fields(obj) != OK)
		return (1);
	apply_transforms(camera);
	return (0);
}

static t_err	lex_checker(t_parser_obj *obj)
{
	if (obj->fields_count != CAMERA_FIELDS_COUNT)
		obj->status = INVALID_ARG_COUNT;
	else if (!is_str_vec3(obj->fields[1]) || !is_str_vec3(obj->fields[2]))
		obj->status = INVALID_VEC3;
	else if (!ft_str_isdigit(obj->fields[3]))
		obj->status = INVALID_ARG;
	return (obj->status);
}

static void	cast_fields(t_parser_obj *obj)
{
	t_camera	*camera;
	t_err		err;

	camera = (t_camera *) obj->obj;
	err = str_to_vec3(obj->fields[1], &camera->pos);
	err |= str_to_vec3(obj->fields[2], &camera->dir);
	if (err != OK)
		obj->status = INVALID_VEC3;
	camera->fov = ft_atoi(obj->fields[3]);
}

static t_err	validate_fields(t_parser_obj *obj)
{
	t_camera	*camera;

	camera = (t_camera *) obj->obj;
	if (!is_valid_direction(&camera->dir))
		obj->status = INVALID_DIRECTION;
	else if (!is_valid_fov(camera->fov))
		obj->status = INVALID_FOV;
	return (obj->status);
}

static void	apply_transforms(t_camera *camera)
{
	t_vec3	up;
	t_vec3	to;
	double	half_view;
	double	aspect;

	camera->fov *= (M_PI / 180);
	camera->hsize = WINDOW_WIDTH;
	camera->vsize = WINDOW_HEIGHT;
	up = (t_vec3){.x = 0.0, .y = 1.0, .z = 0.0};
	add(&camera->pos, &camera->dir, &to);
	camera->transform = view_transform(&camera->pos, &to, &up);
	camera->inv_transform = matrix_inverse(camera->transform);
	half_view = tan(camera->fov / 2.0);
	aspect = (double) camera->hsize / (double) camera->vsize;
	camera->half_height = half_view;
	camera->half_width = half_view;
	if (aspect >= 1.0)
		camera->half_height /= aspect;
	else
		camera->half_width *= aspect;
	camera->pixel_size = camera->half_width * 2.0 / camera->hsize;
}
