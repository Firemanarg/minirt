/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:38:35 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 17:14:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static t_err	plane_intersect(t_geom_obj *plane, t_ray *ray, t_varray *r)
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

static void	plane_map_uv(t_geom_obj *plane, t_vec3 *p, double *u, double *v)
{
	(void)plane;
	*u = fmod(p->x, 1);
	*v = fmod(p->y, 1);
}

t_err	set_plane(t_geom_obj *plane, t_matrix *transform, t_material *material)
{
	plane->type = PLANE;
	plane->intersects = (t_isect_func)plane_intersect;
	plane->normal_at = plane_normal_at;
	plane->map_uv = plane_map_uv;
	return (set_object(plane, transform, material));
}
