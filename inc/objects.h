/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:44:47 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/23 23:09:22 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <vec3.h>
# include <error.h>
# include <varray.h>
# include <matrix.h>
# include <shading.h>

typedef struct s_obj	t_obj;
typedef t_err			(*t_isect_func)(struct s_obj *obj, void *ray,
							t_varray * r);
typedef void			(*t_normal_func)(t_obj *s, t_vec3 *world_point,
							t_vec3 *world_normal);

typedef enum e_shape
{
	UNKNOWN,
	SPHERE,
	CYLINDER,
	PLANE
}	t_shape;

struct s_obj
{
	t_material		material;
	t_shape			type;
	t_matrix		*transform;
	t_matrix		*inv_transform;
	t_matrix		*t_inv_transform;
	t_isect_func	intersects;
	t_normal_func	normal_at;
};

typedef struct s_sphere_eq_pars
{
	double	a;
	double	b;
	double	c;
	double	sqrt_disc;
	t_vec3	origin;
	t_vec3	tmp;
}	t_sphere_eq_pars;

// cleanup.c
void	free_obj(t_obj *obj);

// color.c
void	set_color(double red, double green, double blue, t_color *c);
int		convert_color(t_color *minirt_color);

// sphere.c
t_err	set_sphere(t_obj *sphere, t_matrix *transform, t_material *material);
t_err	set_sphere_transform(t_obj *sphere, t_matrix *transform);
void	sphere_normal_at(t_obj *s, t_vec3 *world_point, t_vec3 *world_normal);

#endif
