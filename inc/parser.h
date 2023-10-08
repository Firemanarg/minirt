/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:53:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/06 12:29:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "objects.h"
# include "error.h"

# define MAX_RATIO 1.0
# define MIN_RATIO 0.0
# define MAX_FOV 180.0
# define MIN_FOV 0.0
# define AMBIENT_LIGHT_FIELDS_COUNT 3
# define CAMERA_FIELDS_COUNT 4
# define LIGHT_FIELDS_COUNT 4
# define SPHERE_FIELDS_COUNT 4
# define CYLINDER_FIELDS_COUNT 6
# define PLANE_FIELDS_COUNT 4

// parser.c
t_scene			*parse_file(char *file_name);
t_base_obj		*parse_line(char *line);
// t_obj_type		get_type_by_str(char *str);

// validations.c
int				is_valid_color(t_vec3 *color);
int				is_valid_ratio(double ratio);
int				is_valid_fov(double fov);
int				is_valid_direction(t_vec3 *dir);

// parse_ambient_light.c
t_ambient_light	*parse_ambient_light(char **fields, int fields_count);

// parse_camera.c
t_camera		*parse_camera(char **fields, int fields_count);

// parse_light.c
t_point_light	*parse_light(char **fields, int fields_count);

// parse_sphere.c
t_sphere		*parse_sphere(char **fields, int fields_count);

// parse_cylinder.c
t_cylinder		*parse_cylinder(char **fields, int fields_count);

// parse_plane.c
t_plane			*parse_plane(char **fields, int fields_count);


#endif