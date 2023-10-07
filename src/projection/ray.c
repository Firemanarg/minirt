/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:59:19 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 12:20:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	set_ray(t_vec3 *start, t_vec3 *direction, t_ray *ray)
{
	ray->start = *start;
	normalize(direction, &ray->direction);
}

void	position(t_ray *ray, double t, t_vec3 *position)
{
	t_vec3	tmp;

	multiply(&ray->direction, t, &tmp);
	add(&ray->start, &tmp, position);
}

void	transform_ray(t_matrix *transform, t_ray *src, t_ray *dst)
{
	matrix_point_multiply(transform, &src->start, &dst->start);
	matrix_vector_multiply(transform, &src->direction, &dst->direction);
}
