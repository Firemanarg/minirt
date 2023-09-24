/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:07:36 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/23 22:39:03 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shading.h>

static double	has_diffuse(t_phong_params *p, t_vec3 *light_v)
{
	subtract(&p->light.position, &p->point, light_v);
	normalize(light_v, light_v);
	return (dot(light_v, &p->normal));
}

static double	has_specular(t_phong_params *p, t_vec3 *light_v)
{
	t_vec3	minus_light_v;
	t_vec3	reflect_v;

	set_vec3(0, 0, 0, &minus_light_v);
	subtract(&minus_light_v, light_v, &minus_light_v);
	reflect(&minus_light_v, &p->normal, &reflect_v);
	return (dot(&reflect_v, &p->eye));
}

void	lighting(t_phong_params *p, t_color *result)
{
	t_color	effective_color;
	t_vec3	light_v;
	t_vec3	tmp;
	double	light_dot_normal;
	double	reflect_dot_eye;

	hadamard(&p->material.color, &p->light.intensity, &effective_color);
	multiply(&effective_color, p->material.ambient, result);
	light_dot_normal = has_diffuse(p, &light_v);
	if (light_dot_normal < 0)
		return ;
	multiply(&effective_color, p->material.diffuse * light_dot_normal, &tmp);
	add(result, &tmp, result);
	reflect_dot_eye = has_specular(p, &light_v);
	if (reflect_dot_eye <= 0)
		return ;
	multiply(&p->light.intensity,
		p->material.specular * pow(reflect_dot_eye, p->material.shininess),
		&tmp);
	add(result, &tmp, result);
}
