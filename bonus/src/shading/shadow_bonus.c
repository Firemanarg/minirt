/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:49:34 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:48:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shading_bonus.h"

t_err	is_shadowed(t_scene *world, t_point_light *light,
			t_precomp *comps, t_varray *xs)
{
	t_vec3	direction;
	double	distance;
	t_ray	ray;
	t_isect	*h;
	t_err	err;

	subtract(&light->pos, &comps->over_point, &direction);
	distance = length(&direction);
	normalize(&direction, &direction);
	set_ray(&comps->over_point, &direction, &ray);
	err = intersect_world(world, &ray, xs);
	if (err != OK)
		return (err);
	h = hit(xs);
	if (h && h->t < distance)
		comps->in_shadow = TRUE;
	else
		comps->in_shadow = FALSE;
	return (OK);
}
