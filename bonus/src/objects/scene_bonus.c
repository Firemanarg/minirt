/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:15:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 11:46:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_bonus.h"

t_scene	*new_scene(int light_count, int geometries_count)
{
	t_scene	*scene;

	scene = (t_scene *) malloc(sizeof(t_scene));
	if (scene == NULL)
		return (NULL);
	scene->lights = (t_point_light *) ft_calloc(
			light_count + 1, sizeof(t_point_light));
	scene->lights[light_count] = (t_point_light){0};
	scene->geometries = (t_geom_obj *) ft_calloc(
			geometries_count + 1, sizeof(t_geom_obj));
	scene->geometries[geometries_count] = (t_geom_obj){0};
	return (scene);
}

void	*free_scene(t_scene *scene)
{
	t_geom_obj	*iter;

	print_msg("Cleaning", "Cleaning scene", TXT_COLOR_MAGENTA);
	if (scene == NULL)
		return (NULL);
	clean_camera(&scene->camera);
	if (scene->geometries != NULL)
	{
		iter = scene->geometries;
		while (iter->type != NONE)
		{
			clean_geometry(iter);
			iter++;
		}
		free(scene->geometries);
	}
	if (scene->lights != NULL)
		free(scene->lights);
	free(scene);
	print_msg("Cleaning", "Scene cleaned", TXT_COLOR_GREEN);
	return (NULL);
}
