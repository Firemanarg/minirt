/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:44:47 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 19:57:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "matrix.h"
# include "vec3.h"
# include "error.h"
# include "varray.h"

typedef t_vec3				t_color;
typedef struct s_geom_obj	t_geom_obj;

typedef t_err				(*t_isect_func)(t_geom_obj *obj, void *ray,
								t_varray * r);

typedef void				(*t_normal_func)(t_geom_obj *s, t_vec3 *world_point,
								t_vec3 *world_normal);

typedef void				(*t_uv_func)(t_geom_obj * obj, t_vec3 *p,
								double *u, double *v);

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_material
{
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	t_color		color;
}	t_material;

typedef enum e_obj_type
{
	UNKNOWN = -1,
	NONE,
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	CYLINDER,
	PLANE,
	CONE
}	t_obj_type;

typedef struct s_base_obj
{
	t_obj_type		type;
}	t_base_obj;

typedef struct s_3d_obj
{
	struct			s_base_obj;
	t_matrix		*transform;
	t_matrix		*inv_transform;
	t_matrix		*t_inv_transform;
}	t_3d_obj;

typedef struct s_checkers
{
	double	width;
	double	height;
	t_color	c1;
	t_color	c2;
}	t_checkers;

struct s_geom_obj
{
	struct			s_3d_obj;
	t_vec3			pos;
	t_vec3			dir;
	t_material		material;
	t_isect_func	intersects;
	t_normal_func	normal_at;
	t_uv_func		map_uv;
	t_checkers		checkers;
	double			minimum;
	double			maximum;
	t_bool			is_closed;
};

typedef struct s_base_light
{
	struct			s_base_obj;
	double			ratio;
	t_color			color;
}	t_base_light;

typedef struct s_ambient_light
{
	struct			s_base_light;
}	t_ambient_light;

typedef struct s_point_light
{
	struct			s_base_light;
	t_vec3			pos;
}	t_point_light;

typedef struct s_camera
{
	struct	s_3d_obj;
	double	fov;
	double	half_width;
	double	half_height;
	double	pixel_size;
	int		hsize;
	int		vsize;
}	t_camera;

typedef struct s_sphere
{
	struct			s_geom_obj;
	double			diameter;
}	t_sphere;

typedef struct s_cylinder
{
	struct			s_geom_obj;
	double			diameter;
	double			height;
}	t_cylinder;

typedef struct s_plane
{
	struct			s_geom_obj;
}	t_plane;

typedef struct s_scene
{
	t_camera		camera;
	t_ambient_light	ambient_light;
	t_geom_obj		*geometries;
	t_point_light	*lights;
}	t_scene;

typedef struct s_cone_eq_params
{
	double	a;
	double	b;
	double	c;
	double	sqrt_disc;
	double	t1;
	double	t2;
}	t_cone_eq_params;

// caps.c
void	set_object_limits(t_geom_obj *cyl, double minimum,
			double maximum, t_bool closed);

// cleanup.c
void	free_obj(t_geom_obj *obj);

// color.c
t_color	color(double red, double green, double blue);
void	set_color(double red, double green, double blue, t_color *c);

// cone.c
void	cone_normal_at(t_geom_obj *c, t_vec3 *obj_point, t_vec3 *obj_normal);
t_err	set_cone(t_geom_obj *cone, t_matrix *transform, t_material *material);
void	cone_map_uv(t_geom_obj *cone, t_vec3 *p, double *u, double *v);

// cylinder.c
void	cylinder_normal_at(t_geom_obj *cyl, t_vec3 *obj_point,
			t_vec3 *obj_normal);
t_err	set_cylinder(t_geom_obj *cyl, t_matrix *transform,
			t_material *material);
void	cylinder_map_uv(t_geom_obj *cyl, t_vec3 *p, double *u, double *v);

// light.c
void	set_point_light(t_vec3 *pos, t_color *color, t_point_light *light);

// material.c
void	set_material_shininess(t_material *material, double shininess);
void	set_material_color(t_material *material, double r, double g, double b);
void	set_material_coefficients(t_material *material, double ambient,
			double diffuse, double specular);

//object.c
t_err	set_object(t_geom_obj *object, t_matrix *transform,
			t_material *material);
t_err	set_object_transform(t_geom_obj *object, t_matrix *transform);
void	obj_normal_at(t_geom_obj *obj, t_vec3 *world_point,
			t_vec3 *world_normal);

// plane.c
void	plane_normal_at(t_geom_obj *p, t_vec3 *object_point,
			t_vec3 *object_normal);
t_err	set_plane(t_geom_obj *plane, t_matrix *transform, t_material *material);
void	plane_map_uv(t_geom_obj *plane, t_vec3 *p, double *u, double *v);

// sphere.c
void	sphere_normal_at(t_geom_obj *sph, t_vec3 *object_point,
			t_vec3 *object_normal);
t_err	set_sphere(t_geom_obj *sph, t_matrix *transform,
			t_material *material);
void	sphere_map_uv(t_geom_obj *sph, t_vec3 *p, double *u, double *v);

#endif