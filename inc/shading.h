/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:11:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/03 03:37:41 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

# include <vec3.h>

typedef t_vec3	t_color;

typedef struct s_point_light
{
	t_color	intensity;
	t_vec3	position;
}	t_point_light;

typedef struct s_material
{
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
	t_color	color;
}	t_material;
# include "objects.h"

typedef struct s_phong_params
{
	t_material		material;
	t_point_light	*light;
	t_vec3			normal;
	t_vec3			eye;
	t_vec3			point;
}	t_phong_params;

// lighting.c
void	lighting(t_phong_params *p, t_color *result);

// material.c
void	set_material_shininess(t_material *material, double shininess);
void	set_material_color(t_material *material, double r, double g, double b);
void	set_material_coefficients(t_material *material, double ambient,
			double diffuse, double specular);

// reflect.c
void	reflect(t_vec3 *incident, t_vec3 *normal, t_vec3 *reflected);

#endif
