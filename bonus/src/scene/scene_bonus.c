/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 02:55:34 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 13:22:52 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "shading_bonus.h"

t_err	intersect_world(t_scene *w, t_ray *r, t_varray *xs)
{
	t_err		err;
	t_geom_obj	*tmp;

	reset_array(xs);
	tmp = w->geometries;
	if (!tmp)
		return (OK);
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
	multiply(&comps->normal, EPSILON, &comps->over_point);
	add(&comps->over_point, &comps->point, &comps->over_point);
}

t_err	shade_hit(t_scene *w, t_precomp *comps, t_color *color, t_varray *xs)
{
	t_err			err;
	t_point_light	*cur_light;
	t_color			partial_color;
	t_geom_obj		*obj;
	t_material		*m;

	obj = comps->obj;
	m = &obj->material;
	partial_color = comps->obj->material.color;
	hadamard(&partial_color, &w->ambient_light.color,
		color);
	multiply(color, comps->obj->material.ambient, color);
	cur_light = w->lights;
	while (cur_light->type == LIGHT)
	{
		err = is_shadowed(w, cur_light, comps, xs);
		if (err != OK)
			return (err);
		partial_color = comps->obj->material.color;
		lighting(comps, m, cur_light++, &partial_color);
		add(color, &partial_color, color);
	}
	return (OK);
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
	err = shade_hit(w, &comps, color, xs);
	if (err != OK)
		return (err);
	return (OK);
}
