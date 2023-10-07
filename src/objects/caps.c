/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:53:53 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 12:19:01 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static t_bool	check_cylinder_cap(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->start.x + t * ray->direction.x;
	z = ray->start.z + t * ray->direction.z;
	return ((x * x + z * z) <= 1.0);
}

t_err	intersect_cylinder_caps(t_obj *cylinder, t_ray *ray, t_varray *xs)
{
	double	t;
	t_err	err;

	err = OK;
	if (!cylinder->is_closed || dbl_abs(ray->direction.y) < EPSILON)
		return (OK);
	t = (cylinder->minimum - ray->start.y) / ray->direction.y;
	if (check_cylinder_cap(ray, t))
		err = insert_into_array(xs, t, cylinder);
	if (err)
		return (err);
	t = (cylinder->maximum - ray->start.y) / ray->direction.y;
	if (check_cylinder_cap(ray, t))
		err = insert_into_array(xs, t, cylinder);
	return (err);
}

static t_bool	check_cone_cap(t_ray *ray, double t, double y)
{
	double	x;
	double	z;

	x = ray->start.x + t * ray->direction.x;
	z = ray->start.z + t * ray->direction.z;
	return ((x * x + z * z) <= y * y);
}

t_err	intersect_cone_caps(t_obj *cone, t_ray *ray, t_varray *xs)
{
	double	t;
	t_err	err;

	if (!cone->is_closed || dbl_abs(ray->direction.y) < EPSILON)
		return (OK);
	err = OK;
	t = (cone->minimum - ray->start.y) / ray->direction.y;
	if (check_cone_cap(ray, t, cone->minimum))
		err = insert_into_array(xs, t, cone);
	if (err)
		return (err);
	t = (cone->maximum - ray->start.y) / ray->direction.y;
	if (check_cone_cap(ray, t, cone->maximum))
		err = insert_into_array(xs, t, cone);
	return (err);
}
