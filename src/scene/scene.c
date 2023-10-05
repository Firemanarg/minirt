/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 02:55:34 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/05 04:34:01 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "projection.h"
#include "minirt.h"


t_err	intersect_world(t_scene *w, t_ray *r, t_varray *xs)
{
	t_err		err;
	t_geom_obj	*tmp;

	tmp = w->geometries;
	while (tmp->type > NONE)
	{
		err = obj_intersect(tmp, r, xs);
		if (err)
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
	if (dot(&comps->normal, &comps->eye) < 0.0)
	{
		comps->inside = TRUE;
		negate(&comps->normal, &comps->normal);
	}
	else
		comps->inside = FALSE;
}
