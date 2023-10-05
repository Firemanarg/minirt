/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:53:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/04 03:23:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "objects.h"
# include "error.h"
# include "vec3.h"

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