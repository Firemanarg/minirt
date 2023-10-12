/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:34:32 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 17:21:29 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static t_err	insert_if_in_range(t_geom_obj *cyl, t_varray *r,
					double t, double y)
{
	if (y > cyl->minimum && y < cyl->maximum)
		return (insert_into_array(r, t, cyl));
	return (OK);
}

static t_err	cylinder_intersect(t_geom_obj *cyl, t_ray *ray, t_varray *r)
{
	double	a;
	double	b;
	double	c;
	double	sqrt_disc;
	double	ts[2];

	a = (ray->direction.x) * (ray->direction.x)
		+ (ray->direction.z) * (ray->direction.z);
	if (dbl_abs(a) < EPSILON)
		return (intersect_cylinder_caps(cyl, ray, r));
	b = 2 * ((ray->start.x) * (ray->direction.x)
			+ (ray->start.z) * (ray->direction.z));
	c = (ray->start.x) * (ray->start.x)
		+ (ray->start.z) * (ray->start.z) - 1;
	sqrt_disc = b * b - 4 * a * c;
	if (sqrt_disc < 0)
		return (intersect_cylinder_caps(cyl, ray, r));
	sqrt_disc = sqrt(sqrt_disc);
	ts[0] = (-b - sqrt_disc) / (2.0 * a);
	ts[1] = (-b + sqrt_disc) / (2.0 * a);
	return (insert_if_in_range(cyl, r, ts[0],
			ray->start.y + ts[0] * ray->direction.y)
		|| insert_if_in_range(cyl, r, ts[1],
			ray->start.y + ts[1] * ray->direction.y)
		|| intersect_cylinder_caps(cyl, ray, r));
}

void	cylinder_normal_at(t_geom_obj *cyl, t_vec3 *obj_point,
			t_vec3 *obj_normal)
{
	double	dist;

	dist = obj_point->x * obj_point->x
		+ obj_point->z * obj_point->z;
	if (dist < 1.0 && obj_point->y >= cyl->maximum - EPSILON)
		set_vec3(0.0, 1.0, 0.0, obj_normal);
	else if (dist < 1 && obj_point->y <= cyl->minimum + EPSILON)
		set_vec3(0.0, -1.0, 0.0, obj_normal);
	else
		set_vec3(obj_point->x, 0.0, obj_point->z, obj_normal);
}

static void	cylinder_map_uv(t_geom_obj *cyl, t_vec3 *p, double *u, double *v)
{
	if (p->y > cyl->minimum && p->y < cyl->maximum)
		*u = 1 - (atan2(p->x, p->z) * 0.5 * M_1_PI + 0.5);
	else
		*u = fmod(p->x, 1);
	*v = fmod(p->y, 1);
}

t_err	set_cylinder(t_geom_obj *cyl, t_matrix *transform, t_material *material)
{
	cyl->type = CYLINDER;
	cyl->intersects = (t_isect_func)cylinder_intersect;
	cyl->normal_at = cylinder_normal_at;
	cyl->map_uv = cylinder_map_uv;
	cyl->minimum = -1.0 / 0.0;
	cyl->maximum = 1.0 / 0.0;
	cyl->is_closed = FALSE;
	return (set_object(cyl, transform, material));
}
