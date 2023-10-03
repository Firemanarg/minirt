/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:44:47 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/26 22:29:52 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <vec3.h>
# include <error.h>
# include <varray.h>
# include <matrix.h>
# include <minirt.h>
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
	PLANE,
	CONE
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
	double			minimum;
	double			maximum;
	t_bool			closed;
};

typedef struct s_cone_eq_params
{
	double	a;
	double	b;
	double	c;
	double	sqrt_disc;
	double	t1;
	double	t2;
}	t_cone_eq_params;

// cleanup.c
void	free_obj(t_obj *obj);

// color.c
void	set_color(double red, double green, double blue, t_color *c);
int		convert_color(t_color *minirt_color);

// cone.c
void	cone_normal_at(t_obj *c, t_vec3 *object_point,
			t_vec3 *object_normal);
t_err	set_cone(t_obj *cone, t_matrix *transform, t_material *material);
void	set_cone_limits(t_obj *cone, double minimum, double maximum,
			t_bool closed);

// cylinder.c
void	cylinder_normal_at(t_obj *c, t_vec3 *object_point,
			t_vec3 *object_normal);
t_err	set_cylinder(t_obj *cylinder, t_matrix *transform,
			t_material *material);
void	set_cylinder_limits(t_obj *cylinder, double minimum, double maximum,
			t_bool closed);

//object.c
t_err	set_object(t_obj *object, t_matrix *transform, t_material *material);
t_err	set_object_transform(t_obj *object, t_matrix *transform);
void	obj_normal_at(t_obj *obj, t_vec3 *world_point, t_vec3 *world_normal);

// plane.c
void	plane_normal_at(t_obj *p, t_vec3 *object_point, t_vec3 *object_normal);
t_err	set_plane(t_obj *plane, t_matrix *transform, t_material *material);

// sphere.c
void	sphere_normal_at(t_obj *s, t_vec3 *object_point, t_vec3 *object_normal);
t_err	set_sphere(t_obj *sphere, t_matrix *transform, t_material *material);

#endif
