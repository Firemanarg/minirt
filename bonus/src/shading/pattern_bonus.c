/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:21:39 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:48:22 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection_bonus.h"

void	uv_checkers_at(t_checkers *checkers, double u, double v, t_color *c)
{
	if (dbl_abs(fmod(floor(u * checkers->width)
				+ floor(v * checkers->height), 2.0)))
		*c = checkers->c2;
	else
		*c = checkers->c1;
}

void	pattern_at(t_geom_obj *obj, t_vec3 *point, t_color *c)
{
	double	u;
	double	v;
	t_vec3	transformed;

	matrix_point_multiply(obj->inv_transform, point, &transformed);
	if (obj->map_uv)
	{
		obj->map_uv(obj, &transformed, &u, &v);
		uv_checkers_at(&obj->checkers, u, v, c);
	}
	else
		*c = obj->material.color;
}
