/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:11:05 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/26 22:26:09 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <objects.h>
#include <varray.h>
#include <projection.h>

static t_err	sphere_intersect(t_obj *sphere, t_ray *ray, t_varray *r)
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
			(-b - sqrt_disc) / (2.0 * a), sphere)
		|| insert_into_array(r,
			(-b + sqrt_disc) / (2.0 * a), sphere));
}

void	sphere_normal_at(t_obj *s, t_vec3 *object_point, t_vec3 *object_normal)
{
	(void)s;
	*object_normal = *object_point;
}

t_err	set_sphere(t_obj *sphere, t_matrix *transform, t_material *material)
{
	sphere->type = SPHERE;
	sphere->intersects = (t_isect_func)sphere_intersect;
	sphere->normal_at = sphere_normal_at;
	return (set_object(sphere, transform, material));
}
