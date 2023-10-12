/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:11:05 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 16:58:12 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static t_err	sphere_intersect(t_geom_obj *sph, t_ray *ray, t_varray *r)
{
	double	a;
	double	b;
	double	c;
	double	sqrt_disc;

	a = dot(&ray->direction, &ray->direction);
	b = 2 * dot(&ray->direction, &ray->start);
	c = dot(&ray->start, &ray->start) - 1;
	sqrt_disc = b * b - 4 * a * c;
	if (sqrt_disc < 0)
		return (OK);
	sqrt_disc = sqrt(sqrt_disc);
	return (insert_into_array(r,
			(-b - sqrt_disc) / (2.0 * a), sph)
		|| insert_into_array(r,
			(-b + sqrt_disc) / (2.0 * a), sph));
}

void	sphere_normal_at(t_geom_obj *sph, t_vec3 *object_point,
			t_vec3 *object_normal)
{
	(void)sph;
	*object_normal = *object_point;
}

t_err	set_sphere(t_geom_obj *sph, t_matrix *transform, t_material *material)
{
	sph->type = SPHERE;
	sph->intersects = (t_isect_func)sphere_intersect;
	sph->normal_at = sphere_normal_at;
	return (set_object(sph, transform, material));
}

void	sphere_map_uv(t_vec3 *p, double *u, double *v)
{
	*u = 1 - (atan2(p->x, p->z) * 0.5 * M_1_PI + 0.5);
	*v = 1 - acos(p->y / length(p)) * M_1_PI;
}
