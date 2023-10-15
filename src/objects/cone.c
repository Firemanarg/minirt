/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:34:32 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/26 02:37:07 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static t_err	insert_if_in_cone_range(t_geom_obj *cone, t_varray *r,
					double t, double y)
{
	if (y > cone->minimum && y < cone->maximum)
		return (insert_into_array(r, t, cone));
	return (OK);
}

static t_err	cone_intersect(t_geom_obj *cone, t_ray *ray, t_varray *r)
{
	t_cone_eq_params	p;

	p.a = (ray->direction.x) * (ray->direction.x) - (ray->direction.y)
		* (ray->direction.y) + (ray->direction.z) * (ray->direction.z);
	p.b = 2 * ((ray->start.x) * (ray->direction.x) - (ray->start.y)
			* (ray->direction.y) + (ray->start.z) * (ray->direction.z));
	p.c = (ray->start.x) * (ray->start.x) - (ray->start.y) * (ray->start.y)
		+ (ray->start.z) * (ray->start.z);
	if (dbl_abs(p.a) < EPSILON)
	{
		if (dbl_abs(p.b) >= EPSILON)
			insert_into_array(r, -p.c / (2 * p.b), cone);
		return (intersect_cone_caps(cone, ray, r));
	}
	p.sqrt_disc = p.b * p.b - 4 * p.a * p.c;
	if (p.sqrt_disc < 0)
		return (OK);
	p.sqrt_disc = sqrt(p.sqrt_disc);
	p.t1 = (-p.b - p.sqrt_disc) / (2.0 * p.a);
	p.t2 = (-p.b + p.sqrt_disc) / (2.0 * p.a);
	return (insert_if_in_cone_range(cone, r, p.t1,
			ray->start.y + p.t1 * ray->direction.y)
		|| insert_if_in_cone_range(cone, r, p.t2,
			ray->start.y + p.t2 * ray->direction.y)
		|| intersect_cone_caps(cone, ray, r));
}

void	cone_normal_at(t_geom_obj *c, t_vec3 *obj_point, t_vec3 *obj_normal)
{
	double	dist;
	double	y;
	double	r_sq;

	dist = obj_point->x * obj_point->x
		+ obj_point->z * obj_point->z;
	r_sq = obj_point->y * obj_point->y;
	if (dist < r_sq && obj_point->y >= c->maximum - EPSILON)
		set_vec3(0.0, 1.0, 0.0, obj_normal);
	else if (dist < r_sq && obj_point->y <= c->minimum + EPSILON)
		set_vec3(0.0, -1.0, 0.0, obj_normal);
	else
	{
		y = sqrt(dist);
		if (obj_point->y > 0.0)
			y = -y;
		set_vec3(obj_point->x, y, obj_point->z, obj_normal);
	}
}

void	cone_map_uv(t_geom_obj *cone, t_vec3 *p, double *u, double *v)
{
	if (p->y > cone->minimum + EPSILON && p->y < cone->maximum - EPSILON)
	{
		*u = 1 - (atan2(p->x, p->z) * 0.5 * M_1_PI + 0.5);
		*v = fmod(p->y, (M_PI * 2)) * 0.5 * M_1_PI;
	}
	else
	{
		*u = fmod(p->x, (M_PI * 2)) * 0.5 * M_1_PI;
		*v = fmod(p->z, (M_PI * 2)) * 0.5 * M_1_PI;
	}
}

t_err	set_cone(t_geom_obj *cone, t_matrix *transform, t_material *material)
{
	cone->type = CONE;
	cone->intersects = (t_isect_func)cone_intersect;
	cone->normal_at = cone_normal_at;
	cone->map_uv = NULL;
	cone->minimum = -1.0 / 0.0;
	cone->maximum = 1.0 / 0.0;
	cone->is_closed = FALSE;
	return (set_object(cone, transform, material));
}
