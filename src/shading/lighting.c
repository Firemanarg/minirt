/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:07:36 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 01:35:02 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shading.h>

static double	has_diffuse(t_precomp *p, t_point_light *l, t_vec3 *light_v)
{
	subtract(&l->pos, &p->point, light_v);
	normalize(light_v, light_v);
	return (dot(light_v, &p->normal));
}

static double	has_specular(t_precomp *p, t_vec3 *light_v)
{
	t_vec3	minus_light_v;
	t_vec3	reflect_v;

	negate(light_v, &minus_light_v);
	reflect(&minus_light_v, &p->normal, &reflect_v);
	return (dot(&reflect_v, &p->eye));
}

void	lighting(t_precomp *p, t_material *m, t_point_light *l, t_color *color)
{
	t_color	effective_color;
	t_vec3	light_v;
	t_vec3	tmp;
	double	light_dot_normal;
	double	reflect_dot_eye;

	hadamard(&m->color, &l->intensity, &effective_color);
	multiply(&effective_color, m->ambient, color);
	light_dot_normal = has_diffuse(p, l, &light_v);
	if (light_dot_normal < 0)
		return ;
	multiply(&effective_color, m->diffuse * light_dot_normal, &tmp);
	add(color, &tmp, color);
	reflect_dot_eye = has_specular(p, &light_v);
	if (reflect_dot_eye <= 0)
		return ;
	multiply(&l->intensity,
		m->specular * pow(reflect_dot_eye, m->shininess),
		&tmp);
	add(color, &tmp, color);
}
