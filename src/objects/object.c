/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:38:35 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 04:11:52 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "projection.h"

t_err	set_object(t_geom_obj *obj, t_matrix *transform,
			t_material *material)
{
	obj->material = *material;
	obj->transform = NULL;
	obj->inv_transform = NULL;
	obj->t_inv_transform = NULL;
	return (set_object_transform(obj, transform));
}

t_err	set_object_transform(t_geom_obj *obj, t_matrix *transform)
{
	free_obj(obj);
	obj->transform = transform;
	if (obj->transform == NULL)
		return (ERR_ALLOC);
	obj->inv_transform = matrix_inverse(transform);
	if (obj->inv_transform == NULL)
		return (ERR_ALLOC);
	obj->t_inv_transform = matrix_transpose(obj->inv_transform);
	if (obj->t_inv_transform == NULL)
		return (ERR_ALLOC);
	return (OK);
}

t_err	obj_intersect(t_geom_obj *obj, t_ray *ray, t_varray *r)
{
	t_ray	transformed;

	transform_ray(obj->inv_transform, ray, &transformed);
	return (obj->intersects(obj, &transformed, r));
}

void	obj_normal_at(t_geom_obj *obj, t_vec3 *world_point,
	t_vec3 *world_normal)
{
	t_vec3	object_point;
	t_vec3	object_normal;

	matrix_point_multiply(obj->inv_transform, world_point, &object_point);
	obj->normal_at(obj, &object_point, &object_normal);
	matrix_vector_multiply(obj->t_inv_transform, &object_normal, world_normal);
	normalize(world_normal, world_normal);
}

void	free_obj(t_geom_obj *obj)
{
	matrix_free(obj->transform);
	matrix_free(obj->inv_transform);
	matrix_free(obj->t_inv_transform);
	obj->transform = NULL;
	obj->inv_transform = NULL;
	obj->t_inv_transform = NULL;
}
