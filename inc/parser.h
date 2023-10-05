/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:53:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/09/28 08:53:15 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "objects.h"
# include "error.h"
# include "vec3.h"

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
t_scene		*parse_file(char *file_name);
t_base_obj	*parse_line(char *line);
t_obj_type	get_type_by_str(char *str);

t_base_obj	*parse_ambient_light(char **fields, int fields_count);
t_base_obj	*parse_camera(char **fields, int fields_count);
t_base_obj	*parse_light(char **fields, int fields_count);
t_base_obj	*parse_sphere(char **fields, int fields_count);
t_base_obj	*parse_cylinder(char **fields, int fields_count);
t_base_obj	*parse_plane(char **fields, int fields_count);

#endif
