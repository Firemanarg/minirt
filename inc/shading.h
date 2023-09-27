/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:11:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/09/27 15:11:53 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

#include "objects.h"

typedef struct s_phong_params
{
	t_material		material;
	t_point_light	*light;
	t_vec3			normal;
	t_vec3			eye;
	t_vec3			point;
}	t_phong_params;

void	lighting(t_phong_params *p, t_color *result);
void	reflect(t_vec3 *incident, t_vec3 *normal, t_vec3 *reflected);

#endif
