/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:11:05 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/23 23:10:10 by gmachado         ###   ########.fr       */
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

t_err	set_sphere(t_obj *sphere, t_matrix *transform, t_material *material)
{
	sphere->type = SPHERE;
	sphere->material = *material;
	sphere->intersects = (t_isect_func)sphere_intersect;
	sphere->normal_at = sphere_normal_at;
	sphere->transform = NULL;
	sphere->inv_transform = NULL;
	sphere->t_inv_transform = NULL;
	return (set_sphere_transform(sphere, transform));
}

t_err	set_sphere_transform(t_obj *sphere, t_matrix *transform)
{
	free_obj(sphere);
	sphere->transform = transform;
	if (sphere->transform == NULL)
		return (ERR_ALLOC);
	sphere->inv_transform = matrix_inverse(transform);
	if (sphere->inv_transform == NULL)
		return (ERR_ALLOC);
	sphere->t_inv_transform = matrix_transpose(sphere->inv_transform);
	if (sphere->t_inv_transform == NULL)
		return (ERR_ALLOC);
	return (OK);
}

void	sphere_normal_at(t_obj *s, t_vec3 *world_point, t_vec3 *world_normal)
{
	t_vec3	obj_point;
	t_vec3	raw_world_normal;

	matrix_point_multiply(s->inv_transform, world_point, &obj_point);
	matrix_vector_multiply(s->t_inv_transform, &obj_point, &raw_world_normal);
	normalize(&raw_world_normal, world_normal);
}
