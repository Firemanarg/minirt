/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:15:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/12 14:15:02 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_scene	*new_scene(int light_count, int geometries_count)
{
	t_scene	*scene;

	scene = (t_scene *) malloc(sizeof(t_scene));
	if (scene == NULL)
		return (NULL);
	scene->ambient_light = NULL;
	scene->cameras = NULL;
	scene->lights = (t_point_light *) ft_calloc(
			sizeof(t_point_light) * light_count + 1);
	scene->geometries = (t_geom_obj *) ft_calloc(
			sizeof(t_geom_obj) * geometries_count + 1);
	return (scene);
}

void	*free_scene(t_scene *scene)
{
	if (scene == NULL)
		return (NULL);
	if (scene->ambient_light != NULL)
		free(scene->ambient_light);
	if (scene->cameras != NULL)
		ft_clear_strarr(scene->cameras);
	if (scene->lights != NULL)
		free(scene->lights);
	if (scene->geometries != NULL)
		free(scene->geometries);
	free(scene);
	return (NULL);
}
