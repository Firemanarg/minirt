/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:30:33 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 11:47:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

t_obj_type	get_type_by_str(char *str)
{
	if (ft_strcmp(str, "A") == 0)
		return (AMBIENT_LIGHT);
	else if (ft_strcmp(str, "C") == 0)
		return (CAMERA);
	else if (ft_strcmp(str, "L") == 0 || ft_strcmp(str, "l") == 0)
		return (LIGHT);
	else if (ft_strcmp(str, "sp") == 0)
		return (SPHERE);
	else if (ft_strcmp(str, "cy") == 0)
		return (CYLINDER);
	else if (ft_strcmp(str, "co") == 0)
		return (CONE);
	else if (ft_strcmp(str, "pl") == 0)
		return (PLANE);
	else
		return (UNKNOWN);
}

void	free_parser_obj(void *obj)
{
	t_parser_obj	*aux;

	aux = (t_parser_obj *) obj;
	if (aux == NULL)
		return ;
	ft_clear_arr((void **) aux->fields, free);
	if (aux->obj != NULL)
	{
		if (aux->type == CAMERA)
			clean_camera((t_camera *) aux->obj);
		else if (aux->type == SPHERE || aux->type == CYLINDER
			|| aux->type == PLANE || aux->type == CONE)
			clean_geometry((t_geom_obj *) aux->obj);
		free(aux->obj);
	}
	free(aux);
}

void	clean_parser_obj(void *obj)
{
	t_parser_obj	*aux;

	aux = (t_parser_obj *) obj;
	if (aux == NULL)
		return ;
	ft_clear_arr((void **) aux->fields, free);
	if (aux->obj != NULL)
		free(aux->obj);
	free(aux);
}
