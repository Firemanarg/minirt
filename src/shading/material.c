/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:27:15 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/23 19:17:07 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shading.h>

void	set_material_shininess(t_material *material, double shininess)
{
	material->shininess = shininess;
}

void	set_material_coefficients(t_material *material, double ambient,
			double diffuse, double specular)
{
	material->ambient = ambient;
	material->diffuse = diffuse;
	material->specular = specular;
}

void	set_material_color(t_material *material, double r, double g, double b)
{
	material->color.r = r;
	material->color.g = g;
	material->color.b = b;
}
