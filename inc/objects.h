/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:44:47 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/21 04:07:07 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <vec3.h>
# include <error.h>
# include <varray.h>
# include <matrix.h>

typedef t_vec3			t_color;
typedef struct s_obj	t_obj;
typedef t_err			(*t_isect_func)(struct s_obj *obj, void *ray,
							t_varray * r);

typedef enum e_shape
{
	UNKNOWN,
	SPHERE,
	CYLINDER,
	PLANE
}	t_shape;

struct s_obj
{
	t_color			color;
	t_shape			type;
	t_matrix		*transform;
	t_matrix		*inv_transform;
	t_isect_func	intersects;
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

// color.c
void	set_color(double red, double green, double blue, t_color *c);
int		convert_color(t_color *minirt_color);

// sphere.c
t_err	set_sphere(t_obj *sphere, t_matrix *transform, t_color *color);
t_err	set_sphere_transform(t_obj *sphere, t_matrix *transform);

#endif
