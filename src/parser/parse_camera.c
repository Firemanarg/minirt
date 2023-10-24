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

	camera = malloc(sizeof(t_camera));
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
		obj->status = INVALID_VEC3;
	else if (!is_valid_fov(camera->fov))
		obj->status = INVALID_ARG;
	return (obj->status);
}

static void	apply_transforms(t_camera *camera)
{
	t_vec3	up;
	t_vec3	to;

	up = (t_vec3){.x = 0.0, .y = 1.0, .z = 0.0};
	add(&camera->pos, &camera->dir, &to);
	camera->transform = view_transform(&camera->pos, &to, &up);
	camera->inv_transform = matrix_inverse(camera->transform);
	set_camera_pars(WINDOW_WIDTH, WINDOW_HEIGHT, camera->fov, camera);
}

// -------- OLD PARSE CAMERA --------

// static int	is_valid(t_camera *camera);

// static void	set_camera_pars(int hsize, int vsize, double fov, t_camera *camera)
// {
// 	double	half_view;
// 	double	aspect;

// 	camera->hsize = hsize;
// 	camera->vsize = vsize;
// 	fov *= (M_PI / 180);
// 	camera->fov = fov;
// 	half_view = tan(fov / 2.0);
// 	aspect = (double)hsize / (double)vsize;
// 	if (aspect >= 1.0)
// 	{
// 		camera->half_width = half_view;
// 		camera->half_height = half_view / aspect;
// 	}
// 	else
// 	{
// 		camera->half_width = half_view * aspect;
// 		camera->half_height = half_view;
// 	}
// 	camera->pixel_size = camera->half_width * 2.0 / camera->hsize;
// }

// t_err	parse_camera(char **fields, int fields_count, t_camera *camera)
// {
// 	t_err	err;
// 	t_vec3	up;
// 	t_vec3	to;

// 	up = (t_vec3){.x = 0.0, .y = 1.0, .z = 0.0};
// 	if (fields_count != CAMERA_FIELDS_COUNT)
// 		return (INVALID_ARG);
// 	if (camera == NULL)
// 		return (INVALID_ARG);
// 	camera->type = CAMERA;
// 	err = str_to_vec3(fields[1], &camera->pos);
// 	err |= str_to_vec3(fields[2], &camera->dir);
// 	add(&camera->pos, &camera->dir, &to);
// 	camera->fov = ft_atoi(fields[3]);
// 	err |= !is_valid(camera);
// 	if (err != OK)
// 		return (INVALID_ARG);
// 	camera->transform = view_transform(&camera->pos, &to, &up);
// 	camera->inv_transform = matrix_inverse(camera->transform);
// 	set_camera_pars(WINDOW_WIDTH, WINDOW_HEIGHT, camera->fov, camera);
// 	return (OK);
// }

// static int	is_valid(t_camera *camera)
// {
// 	if (!is_valid_direction(&camera->dir))
// 		return (0);
// 	else if (!is_valid_fov(camera->fov))
// 		return (0);
// 	return (1);
// }
