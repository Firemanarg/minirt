/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:53:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 13:52:03 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <fcntl.h>
# include "objects.h"
# include "error.h"
# include "libft_x.h"
# include "ft_list.h"

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

# define PARSER_BUFFER_SIZE 4096

typedef union u_def_obj
{
	t_base_obj		b;
	t_ambient_light	a;
	t_camera		c;
	t_point_light	l;
	t_sphere		sp;
	t_cylinder		cy;
	t_plane			pl;
}	t_def_obj;

/**
 * @brief Struct to hold the parser scene data
 *
 * @param scene Pointer to the scene
 * @param objs List of objects
 * @param err_flag Flag to indicate if there was an error
 * @param fd File descriptor
 * @param amb_light_count Number of ambient lights
 * @param camera_count Number of cameras
 * @param light_count Number of lights
 * @param geometry_count Number of geometries
 * @param light_index Index of the light
 * @param geometry_index Index of the geometry
*/
typedef struct s_scene_parser
{
	char		*line;
	t_scene		*scene;
	t_ftlist	objs;
	int			err_flag;
	int			fd;
	int			amb_light_count;
	int			camera_count;
	int			light_count;
	int			geometry_count;
	int			light_index;
	int			geometry_index;
}	t_scene_parser;

/**
 * @brief Struct to hold the parser object data
 *
 * @param parser Pointer to the scene parser
 * @param type Type of the object
 * @param fields Array of strings with the object fields
 * @param fields_count Number of fields
 * @param obj Pointer to the object
 * @param status Status of the object parsing
 * @param line Line of the object in the file
*/
typedef struct s_parser_obj
{
	t_scene_parser	*parser;
	t_obj_type		type;
	char			**fields;
	int				fields_count;
	void			*obj;
	t_err			status;
	int				line;
}	t_parser_obj;

typedef struct s_line_parser
{
	char	*aux;
	char	*line;
	char	*iter;
	char	*endl_ptr;
}	t_line_parser;

// parser_1.c
t_scene		*parse_file(char *file_name);

// parser_2.c
void		assign_parser_to_objs(t_scene_parser *parser);
void		populate_scene(t_scene_parser *parser);
int			print_parser_errors(t_scene_parser *parser);

// parse_ambient_light.c
int			parse_ambient_light(t_parser_obj *obj);

// parse_camera.c
int			parse_camera(t_parser_obj *obj);

// parse_cylinder.c
int			parse_cylinder(t_parser_obj *obj);

// parse_light.c
int			parse_light(t_parser_obj *obj);

// parse_plane.c
int			parse_plane(t_parser_obj *obj);

// parse_sphere.c
int			parse_sphere(t_parser_obj *obj);

// parser_utils.c
void		clean_parser_obj(void *obj);
void		free_parser_obj(void *obj);
t_obj_type	get_type_by_str(char *str);

// validations.c
int			is_str_vec3(char *str);
int			is_valid_color(t_vec3 *color);
int			is_valid_direction(t_vec3 *dir);
int			is_valid_fov(double fov);
int			is_valid_ratio(double ratio);

#endif
