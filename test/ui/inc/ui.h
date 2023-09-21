/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:41:33 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/21 03:43:01 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <minirt.h>
#include <graphics.h>
#include <varray.h>
#include <projection.h>
#include <objects.h>
#include <matrix.h>
#include <error.h>
#include <vec3.h>

typedef struct s_trace_args
{
	double		wall_z;
	double		wall_size;
	double		pixel_size;
	int			canvas_pixels;
	t_vec3		ray_origin;
	t_varray	*intersections;
	t_ray		ray;
	t_obj		obj;
}	t_trace_args;