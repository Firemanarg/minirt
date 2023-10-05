/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:32:58 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/04 11:59:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "vec3.h"
# include "objects.h"
# include "varray.h"

typedef struct s_isect
{
	double	t;
	t_obj	*obj;
}	t_isect;

typedef struct s_ray
{
	t_vec3	start;
	t_vec3	direction;
}	t_ray;

// caps.c
t_err	intersect_cylinder_caps(t_obj *cylinder, t_ray *ray, t_varray *xs);
t_err	intersect_cone_caps(t_obj *cone, t_ray *ray, t_varray *xs);

// object.c
t_err	obj_intersect(t_obj *obj, t_ray *ray, t_varray *r);

// var_array.c
t_err	insert_into_array(t_varray *r, double t, t_obj *obj);

// ray.c
void	new_ray(t_vec3 *start, t_vec3 *direction, t_ray *ray);
void	position(t_ray *ray, double t, t_vec3 *position);
void	transform_ray(t_matrix *transform, t_ray *src, t_ray *dst);

// hit.c
t_isect	*hit(t_varray *r);

#endif