/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:44:47 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 13:51:00 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "matrix.h"
# include "vec3.h"
# include "error.h"
# include "varray.h"

# define AMBIENT 0.2
# define DIFFUSE 0.9

typedef t_vec3				t_color;
typedef struct s_geom_obj	t_geom_obj;

typedef t_err				(*t_isect_func)(t_geom_obj *obj, void *ray,
								t_varray * r);

typedef void				(*t_normal_func)(t_geom_obj *s, t_vec3 *world_point,
								t_vec3 *world_normal);

typedef void				(*t_uv_func)(t_geom_obj * obj, t_vec3 *p,
								double *u, double *v);

typedef struct s_material
{
	double		ambient;
	double		diffuse;
	t_color		color;
}	t_material;

typedef enum e_obj_type
{
	UNKNOWN = -1,
	NONE = 0,
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	CYLINDER,
	PLANE
}	t_obj_type;

typedef struct s_checkers
{
	double	width;
	double	height;
	t_color	c1;
	t_color	c2;
}	t_checkers;

struct s_geom_obj
{
	t_obj_type		type;
	t_vec3			pos;
	t_vec3			dir;
	t_matrix		*transform;
	t_matrix		*inv_transform;
	t_matrix		*t_inv_transform;
	t_material		material;
	t_isect_func	intersects;
	t_normal_func	normal_at;
	double			diameter;
	double			height;
	double			minimum;
	double			maximum;
	t_bool			is_closed;
};

typedef struct s_ambient_light
{
	t_obj_type		type;
	double			ratio;
	t_color			color;
}	t_ambient_light;

typedef struct s_point_light
{
	t_obj_type		type;
	double			ratio;
	t_color			color;
	t_vec3			pos;
}	t_point_light;

typedef struct s_camera
{
	t_obj_type		type;
	t_vec3			pos;
	t_vec3			dir;
	t_matrix		*transform;
	t_matrix		*inv_transform;
	t_matrix		*t_inv_transform;
	double			fov;
	double			half_width;
	double			half_height;
	double			pixel_size;
	int				hsize;
	int				vsize;
}	t_camera;

typedef t_geom_obj			t_sphere;

typedef t_geom_obj			t_cylinder;

typedef t_geom_obj			t_plane;

typedef struct s_base_obj
{
	union {
		t_camera	c;
		t_geom_obj	g;
	};
}	t_base_obj;

typedef struct s_scene
{
	t_camera		camera;
	t_ambient_light	ambient_light;
	t_geom_obj		*geometries;
	t_point_light	*lights;
}	t_scene;

// caps.c
void	set_object_limits(t_geom_obj *cyl, double minimum,
			double maximum, t_bool closed);

// clean_obj.c
void	clean_camera(t_camera *obj);
void	clean_geometry(t_geom_obj *obj);
void	clean_obj(t_base_obj *obj);

// color.c
t_color	color(double red, double green, double blue);
void	set_color(double red, double green, double blue, t_color *c);

// cylinder.c
void	cylinder_normal_at(t_geom_obj *cyl, t_vec3 *obj_point,
			t_vec3 *obj_normal);
t_err	set_cylinder(t_geom_obj *cyl, t_matrix *transform,
			t_material *material);

// light.c
void	set_point_light(t_vec3 *pos, t_color *color, t_point_light *light);

// material.c
void	set_material_coefficients(t_material *material, double ambient,
			double diffuse);
void	set_material_color(t_material *material, double r, double g, double b);

// obj_utils.c
char	*get_obj_name(t_obj_type type);

//object.c
void	free_obj(t_geom_obj *obj);
void	obj_normal_at(t_geom_obj *obj, t_vec3 *world_point,
			t_vec3 *world_normal);
t_err	set_object(t_geom_obj *object, t_matrix *transform,
			t_material *material);
t_err	set_object_transform(t_geom_obj *object, t_matrix *transform);

// plane.c
void	plane_normal_at(t_geom_obj *p, t_vec3 *object_point,
			t_vec3 *object_normal);
t_err	set_plane(t_geom_obj *plane, t_matrix *transform, t_material *material);

// scene.c
void	*free_scene(t_scene *scene);
t_scene	*new_scene(int light_count, int geometries_count);

// sphere.c
t_err	set_sphere(t_geom_obj *sph, t_matrix *transform,
			t_material *material);
void	sphere_normal_at(t_geom_obj *sph, t_vec3 *object_point,
			t_vec3 *object_normal);

#endif
