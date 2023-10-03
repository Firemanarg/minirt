/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:34:32 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/26 22:25:52 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <objects.h>
#include <varray.h>
#include <projection.h>

static t_err	insert_if_in_range(t_obj *cylinder, t_varray *r,
					double t, double y)
{
	if (y > cylinder->minimum && y < cylinder->maximum)
		return (insert_into_array(r, t, cylinder));
	return (OK);
}

static t_err	cylinder_intersect(t_obj *cylinder, t_ray *ray, t_varray *r)
{
	double	a;
	double	b;
	double	c;
	double	sqrt_disc;
	double	ts[2];

	a = (ray->direction.x) * (ray->direction.x)
		+ (ray->direction.z) * (ray->direction.z);
	if (dbl_abs(a) < EPSILON)
		return (intersect_cylinder_caps(cylinder, ray, r));
	b = 2 * ((ray->start.x) * (ray->direction.x)
			+ (ray->start.z) * (ray->direction.z));
	c = (ray->start.x) * (ray->start.x)
		+ (ray->start.z) * (ray->start.z) - 1;
	sqrt_disc = b * b - 4 * a * c;
	if (sqrt_disc < 0)
		return (intersect_cylinder_caps(cylinder, ray, r));
	sqrt_disc = sqrt(sqrt_disc);
	ts[0] = (-b - sqrt_disc) / (2.0 * a);
	ts[1] = (-b + sqrt_disc) / (2.0 * a);
	return (insert_if_in_range(cylinder, r, ts[0],
			ray->start.y + ts[0] * ray->direction.y)
		|| insert_if_in_range(cylinder, r, ts[1],
			ray->start.y + ts[1] * ray->direction.y)
		|| intersect_cylinder_caps(cylinder, ray, r));
}

void	cylinder_normal_at(t_obj *c, t_vec3 *object_point,
			t_vec3 *object_normal)
{
	double	dist;

	dist = object_point->x * object_point->x
		+ object_point->z * object_point->z;
	if (dist < 1.0 && object_point->y >= c->maximum - EPSILON)
		set_vec3(0.0, 1.0, 0.0, object_normal);
	else if (dist < 1 && object_point->y <= c->minimum + EPSILON)
		set_vec3(0.0, -1.0, 0.0, object_normal);
	else
		set_vec3(object_point->x, 0.0, object_point->z, object_normal);
}

t_err	set_cylinder(t_obj *cylinder, t_matrix *transform, t_material *material)
{
	cylinder->type = CYLINDER;
	cylinder->intersects = (t_isect_func)cylinder_intersect;
	cylinder->normal_at = cylinder_normal_at;
	cylinder->minimum = -1.0 / 0.0;
	cylinder->maximum = 1.0 / 0.0;
	cylinder->closed = FALSE;
	return (set_object(cylinder, transform, material));
}

void	set_cylinder_limits(t_obj *cylinder, double minimum, double maximum,
			t_bool closed)
{
	cylinder->minimum = minimum;
	cylinder->maximum = maximum;
	cylinder->closed = closed;
}
