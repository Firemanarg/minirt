/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:53:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 06:51:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

/**
 * @brief Clears the memory allocated for an object. If the object is a
 * geometry, it also clears the memory allocated for its matrixes.
 *
 * @param obj The object to be cleared.
*/
void	clean_obj(t_base_obj *obj)
{
	if (obj == NULL)
		return ;
	if (obj->c.type == CAMERA || obj->g.type == SPHERE
		|| obj->g.type == CYLINDER || obj->g.type == PLANE)
	{
		matrix_free(((t_geom_obj *) obj)->transform);
		matrix_free(((t_geom_obj *) obj)->inv_transform);
		matrix_free(((t_geom_obj *) obj)->t_inv_transform);
	}
}

void	clean_geometry(t_geom_obj *obj)
{
	if (obj == NULL)
		return ;
	matrix_free(obj->transform);
	matrix_free(obj->inv_transform);
	matrix_free(obj->t_inv_transform);
}

void	clean_camera(t_camera *obj)
{
	if (obj == NULL)
		return ;
	matrix_free(obj->transform);
	matrix_free(obj->inv_transform);
	matrix_free(obj->t_inv_transform);
}
