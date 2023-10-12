/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:21:39 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 04:20:37 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	uv_checkers_at(t_checkers *checkers, double u, double v, t_color *c)
{
	if ((int)(floor(u * checkers->width) + floor(v * checkers->height)) % 2)
		*c = checkers->c2;
	else
		*c = checkers->c1;
}

void	pattern_at(t_geom_obj *obj, t_vec3 *point, t_color *c)
{
	double	u;
	double	v;

	obj->map_uv(point, &u, &v);
	uv_checkers_at(&obj->checkers, u, v, c);
}
