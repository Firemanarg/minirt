/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:32:58 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 01:23:27 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include <vec3.h>
# include <objects.h>
# include <v_array.h>

typedef struct s_isect
{
	double	t;
	t_obj	*obj;
}	t_isect;

typedef struct s_ray
{
	t_vec3	*start;
	t_vec3	*direction;
}	t_ray;

// var_array.c
t_err	insert_into_array(t_varray *r, double t, t_obj *obj);

// sphere.c
t_err	sphere_intersect(t_obj *sphere, t_ray *ray, t_varray *r);

// ray.c
void	new_ray(t_vec3 *start, t_vec3 *direction, t_ray *ray);
void	position(t_ray *ray, double t, t_vec3 *position);

// hit.c
t_isect	*hit(t_varray *r);

#endif
