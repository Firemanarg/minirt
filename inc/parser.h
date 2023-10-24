/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:53:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 06:45:28 by gmachado         ###   ########.fr       */
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

// typedef struct s_scene_parser
// {
// 	t_scene		*scene;
// 	t_def_obj	obj;
// 	char		*line;
// 	int			fd;
// 	int			amb_light_count;
// 	int			camera_count;
// 	int			light_count;
// 	int			geometry_count;
// 	int			light_index;
// 	int			geometry_index;
// }	t_scene_parser;

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
	char		*line;	// TEMPORARY
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
t_scene			*parse_file(char *file_name);

// parser_2.c
void			assign_parser_to_objs(t_scene_parser *parser);
int				print_parser_errors(t_scene_parser *parser);
void			populate_scene(t_scene_parser *parser);

// parser_utils.c
t_obj_type		get_type_by_str(char *str);
void			free_parser_obj(void *obj);

// validations.c
int				is_valid_color(t_vec3 *color);
int				is_valid_ratio(double ratio);
int				is_valid_fov(double fov);
int				is_valid_direction(t_vec3 *dir);
int				is_str_vec3(char *str);

// parse_ambient_light.c
int				parse_ambient_light(t_parser_obj *obj);
// t_err			parse_ambient_light(char **fields, int fields_count,
// 					t_ambient_light *light);

// parse_camera.c
int				parse_camera(t_parser_obj *obj);
// t_err			parse_camera(char **fields, int fields_count,
// 					t_camera *camera);

// parse_light.c
t_err			parse_light(char **fields, int fields_count,
					t_point_light *light);

// parse_sphere.c
t_err			parse_sphere(char **fields, int fields_count,
					t_sphere *sphere);

// parse_cylinder.c
t_err			parse_cylinder(char **fields, int fields_count,
					t_cylinder *cylinder);

// parse_plane.c
t_err			parse_plane(char **fields, int fields_count,
					t_plane *plane);

// get_scene_parser_args.c
t_scene_parser	*get_scene_parser_args(char const *file_name);

#endif
