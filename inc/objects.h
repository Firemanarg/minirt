/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:44:47 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 12:14:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include <vec3.h>
# include <error.h>
# include <varray.h>

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
	t_vec3			pos;
	t_shape			type;
	t_color			color;
	double			diameter;
	double			height;
	t_isect_func	intersects;
};

// color.c
t_color	color(double red, double green, double blue);

#endif
