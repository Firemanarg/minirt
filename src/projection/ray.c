/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:59:19 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/16 21:53:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3.h>
#include <projection.h>

void	new_ray(t_vec3 *start, t_vec3 *direction, t_ray *ray)
{
	ray->start = start;
	ray->direction = direction;
}

void	position(t_ray *ray, double t, t_vec3 *position)
{
	t_vec3	tmp;

	multiply(ray->direction, t, &tmp);
	add(ray->start, &tmp, position);
}
