/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:55:20 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 14:39:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

# include "projection.h"
# include "graphics.h"

// lighting.c
void		lighting(t_precomp *p, t_material *m, t_point_light *l,
				t_color *color);

//reflect.c
void		reflect(t_vec3 *incident, t_vec3 *normal, t_vec3 *reflected);

// render.c
void		ray_for_pixel(t_camera *camera, int p_x, int p_y, t_ray *ray);
t_err		render_image(t_camera *camera, t_scene *world,
				t_mlx_data *mlx_data);

// scene.c
void		shade_hit(t_scene *w, t_precomp *comp, t_color *color);
t_err		color_at(t_scene *w, t_ray *r, t_varray *xs, t_color *color);

// view.c
t_matrix	*view_transform(t_vec3 *from, t_vec3 *to, t_vec3 *up);

#endif