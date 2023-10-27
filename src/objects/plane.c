/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:38:35 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 03:35:56 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

t_err	plane_intersect(t_geom_obj *plane, t_ray *ray, t_varray *r)
{
	if (dbl_abs(ray->direction.y) < EPSILON)
		return (OK);
	return (insert_into_array(r, -ray->start.y / ray->direction.y, plane));
}

void	plane_normal_at(t_geom_obj *p, t_vec3 *object_point,
			t_vec3 *object_normal)
{
	(void)p;
	(void)object_point;
	set_vec3(0.0, 1.0, 0.0, object_normal);
}

t_err	set_plane(t_geom_obj *plane, t_matrix *transform, t_material *material)
{
	plane->type = PLANE;
	plane->intersects = (t_isect_func)plane_intersect;
	plane->normal_at = plane_normal_at;
	return (set_object(plane, transform, material));
}
