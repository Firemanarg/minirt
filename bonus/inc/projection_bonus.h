/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:32:58 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:37:25 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_BONUS_H
# define PROJECTION_BONUS_H

# include "objects_bonus.h"

# define INITIAL_ARRAY_SIZE 8

typedef struct s_isect
{
	double		t;
	t_geom_obj	*obj;
}	t_isect;

typedef struct s_ray
{
	t_vec3	start;
	t_vec3	direction;
}	t_ray;

typedef struct s_precomp
{
	double			t;
	t_geom_obj		*obj;
	t_vec3			point;
	t_vec3			normal;
	t_vec3			eye;
	t_vec3			over_point;
	t_bool			inside;
	t_bool			in_shadow;
}	t_precomp;

// caps.c
t_err	intersect_cylinder_caps(t_geom_obj *cylinder, t_ray *ray, t_varray *xs);
t_err	intersect_cone_caps(t_geom_obj *cone, t_ray *ray, t_varray *xs);

// cone.c
t_err	cone_intersect(t_geom_obj *cone, t_ray *ray, t_varray *xs);

// cylinder.c
t_err	cylinder_intersect(t_geom_obj *cylinder, t_ray *ray, t_varray *xs);

// object.c
t_err	obj_intersect(t_geom_obj *obj, t_ray *ray, t_varray *r);

// plane.c
t_err	plane_intersect(t_geom_obj *plane, t_ray *ray, t_varray *r);

// sphere.c
t_err	sphere_intersect(t_geom_obj *sphere, t_ray *ray, t_varray *r);

// var_array.c
t_err	insert_into_array(t_varray *r, double t, t_geom_obj *obj);

// ray.c
void	set_ray(t_vec3 *start, t_vec3 *direction, t_ray *ray);
void	position(t_ray *ray, double t, t_vec3 *position);
void	transform_ray(t_matrix *transform, t_ray *src, t_ray *dst);

// hit.c
t_isect	*hit(t_varray *r);

// scene.c
t_err	intersect_world(t_scene *w, t_ray *r, t_varray *xs);
void	prepare_computations(t_isect *i, t_ray *r, t_precomp *comps);

// camera.c
void	set_camera(int hsize, int vsize, double fov, t_camera *camera);
t_err	set_camera_transform(t_matrix *transform, t_camera *camera);
void	free_camera(t_camera *camera);

// pattern.c
void	uv_checkers_at(t_checkers *checkers, double u, double v, t_color *c);
void	pattern_at(t_geom_obj *obj, t_vec3 *point, t_color *c);

#endif
