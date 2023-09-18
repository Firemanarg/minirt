/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:11:05 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 03:57:07 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <objects.h>
#include <v_array.h>
#include <projection.h>

t_err	sphere_intersect(t_obj *sphere, t_ray *ray, t_varray *r)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	t_vec3	vecs[2];

	set_vec3(0.0, 0.0, 0.0, vecs);
	subtract(ray->start, vecs, vecs + 1);
	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, vecs + 1);
	c = dot(vecs + 1, vecs + 1) - 1;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (OK);
	return (insert_into_array(r, (-b - sqrt(disc)) / (2.0 * a), sphere)
		|| insert_into_array(r, (-b + sqrt(disc)) / (2.0 * a), sphere));
}
