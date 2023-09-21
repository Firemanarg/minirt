/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:11:05 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/20 10:16:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <objects.h>
#include <varray.h>
#include <projection.h>

t_err	sphere_intersect(t_obj *sphere, t_ray *ray, t_varray *r)
{
	t_sphere_eq_pars	pars;
	t_ray				transformed;

	transform_ray(sphere->inv_transform, ray, &transformed);
	set_vec3(0.0, 0.0, 0.0, &pars.origin);
	subtract(&transformed.start, &pars.origin, &pars.tmp);
	pars.a = dot(&transformed.direction, &transformed.direction);
	pars.b = 2 * dot(&transformed.direction, &pars.tmp);
	pars.c = dot(&pars.tmp, &pars.tmp) - 1;
	pars.sqrt_disc = pars.b * pars.b - 4 * pars.a * pars.c;
	if (pars.sqrt_disc < 0)
		return (OK);
	pars.sqrt_disc = sqrt(pars.sqrt_disc);
	return (insert_into_array(r,
			(-pars.b - pars.sqrt_disc) / (2.0 * pars.a), sphere)
		|| insert_into_array(r,
			(-pars.b + pars.sqrt_disc) / (2.0 * pars.a), sphere));
}

t_err	set_sphere(t_obj *sphere, t_matrix *transform, t_color *color)
{
	sphere->type = SPHERE;
	sphere->color = *color;
	sphere->intersects = (t_isect_func)sphere_intersect;
	sphere->transform = transform;
	if (sphere->transform == NULL)
		return (ERR_ALLOC);
	sphere->inv_transform = matrix_inverse(transform);
	if (sphere->inv_transform == NULL)
	{
		matrix_free(sphere->transform);
		return (ERR_ALLOC);
	}
	return (OK);
}

t_err	set_sphere_transform(t_obj *sphere, t_matrix *transform)
{
	matrix_free(sphere->transform);
	matrix_free(sphere->inv_transform);
	sphere->transform = transform;
	if (sphere->transform == NULL)
		return (ERR_ALLOC);
	sphere->inv_transform = matrix_inverse(transform);
	if (sphere->inv_transform == NULL)
	{
		matrix_free(sphere->transform);
		return (ERR_ALLOC);
	}
	return (OK);
}
