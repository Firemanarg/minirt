/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:48 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 14:56:25 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "projection.h"

static int	is_valid(t_sphere *sphere);
static void	apply_scaling(t_sphere *sphere);

static void	set_sphere_pars(t_sphere *sphere)
{
	sphere->intersects = (t_isect_func)sphere_intersect;
	sphere->normal_at = sphere_normal_at;
	sphere->map_uv = NULL;
	sphere->material.color.r /= 255.0;
	sphere->material.color.g /= 255.0;
	sphere->material.color.b /= 255.0;
	sphere->material.diffuse = DIFFUSE;
	sphere->material.specular = SPECULAR;
	sphere->material.ambient = AMBIENT;
}

t_err	parse_sphere(char **fields, int fields_count, t_sphere *sphere)
{
	t_err	err;

	if (fields_count != SPHERE_FIELDS_COUNT)
		return (INVALID_ARG);
	if (sphere == NULL)
		return (INVALID_ARG);
	sphere->type = SPHERE;
	err = str_to_vec3(fields[1], &sphere->pos);
	sphere->diameter = ft_atod(fields[2]);
	err |= str_to_vec3(fields[3], &(sphere->material.color));
	err |= !is_valid(sphere);
	if (err != OK)
		return (INVALID_ARG);
	sphere->transform = matrix_translation(&sphere->pos);
	apply_scaling(sphere);
	sphere->inv_transform = matrix_inverse(sphere->transform);
	sphere->t_inv_transform = matrix_transpose(sphere->inv_transform);
	set_sphere_pars(sphere);
	return (OK);
}

static int	is_valid(t_sphere *sphere)
{
	if (!is_valid_color(&(sphere->material.color)))
		return (0);
	else if (sphere->diameter <= 0)
		return (0);
	return (1);
}

static void	apply_scaling(t_sphere *sphere)
{
	t_vec3		scale_v;
	t_matrix	*tmp;
	t_matrix	*scale_m;

	set_vec3(sphere->diameter, sphere->diameter, sphere->diameter, &scale_v);
	scale_m = matrix_scaling(&scale_v);
	tmp = matrix_multiply(scale_m, sphere->transform);
	matrix_free(scale_m);
	matrix_free(sphere->transform);
	sphere->transform = tmp;
}
