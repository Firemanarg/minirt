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

# include <unistd.h>
# include <fcntl.h>
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

typedef struct s_scene_parser
{
	t_scene		*scene;
	t_base_obj	*obj;
	char		*line;
	int			fd;
	int			amb_light_count;
	int			camera_count;
	int			light_count;
	int			geometry_count;
}	t_scene_parser;

// parser.c
t_scene			*parse_file(char *file_name);
t_base_obj		*parse_line(char *line);
t_obj_type		get_type_by_str(char *str);

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

// get_scene_parser_args.c
t_scene_parser	*get_scene_parser_args(char const *file_name);

#endif
