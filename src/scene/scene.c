/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 02:55:34 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 02:51:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "projection.h"
#include "minirt.h"
#include "shading.h"


t_err	intersect_world(t_scene *w, t_ray *r, t_varray *xs)
{
	t_err		err;
	t_geom_obj	*tmp;

	reset_array(xs);
	tmp = w->geometries;
	while (tmp->type > NONE)
	{
		err = obj_intersect(tmp, r, xs);
		if (err != OK)
			return (err);
		++tmp;
	}
	quicksort(xs);
	return (OK);
}

void	free_world(t_scene *w)
{
	t_geom_obj	*tmp;

	tmp = w->geometries;
	while (tmp->type > NONE)
	{
		free_obj(tmp);
		++tmp;
	}
	free(w->geometries);
	free(w->lights);
}

void	prepare_computations(t_isect *i, t_ray *r, t_precomp *comps)
{
	comps->t = i->t;
	comps->obj = i->obj;
	position(r, comps->t, &comps->point);
	negate(&r->direction, &comps->eye);
	obj_normal_at(comps->obj, &comps->point, &comps->normal);
	if (dot(&comps->normal, &comps->eye) < EPSILON)
	{
		comps->inside = TRUE;
		negate(&comps->normal, &comps->normal);
	}
	else
		comps->inside = FALSE;
}

void	shade_hit(t_scene *w, t_precomp *comps, t_color *color)
{
	lighting(comps, &(comps->obj->material), w->lights, color);
}

t_err	color_at(t_scene *w, t_ray *r, t_varray *xs, t_color *color)
{
	t_err		err;
	t_isect		*h;
	t_precomp	comps;

	err = intersect_world(w, r, xs);
	if (err != OK)
		return (err);
	h = hit(xs);
	if (!h)
	{
		set_color(0.0, 0.0, 0.0, color);
		return (OK);
	}
	prepare_computations(h, r, &comps);
	shade_hit(w, &comps, color);
	return (OK);
}
