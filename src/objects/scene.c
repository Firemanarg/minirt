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
	scene->camera = NULL;
	scene->lights = (t_point_light **) ft_calloc(
			light_count + 1, sizeof(t_point_light *));
	scene->geometries = (t_geom_obj **) ft_calloc(
			geometries_count + 1, sizeof(t_geom_obj *));
	return (scene);
}

static void	free_3d_obj(void *ptr);

void	*free_scene(t_scene *scene)
{
	if (scene == NULL)
		return (NULL);
	if (scene->ambient_light != NULL)
		free(scene->ambient_light);
	if (scene->camera != NULL)
		free(scene->camera);
	if (scene->lights != NULL)
		ft_clear_arr((void **) scene->lights, NULL);
	if (scene->geometries != NULL)
		ft_clear_arr((void **) scene->geometries, &free_3d_obj);
	free(scene);
	return (NULL);
}

static void	free_3d_obj(void *ptr)
{
	t_3d_obj	*obj;

	obj = (t_3d_obj *) ptr;
	if (obj == NULL)
		return ;
	matrix_free(obj->transform);
	matrix_free(obj->inv_transform);
	matrix_free(obj->t_inv_transform);
	free(obj);
}
