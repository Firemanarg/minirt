/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_obj_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:53:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 11:45:57 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_bonus.h"

/**
 * @brief Frees the memory allocated for a geometry object.
 *
 * @param obj The geometry object to be freed.
*/
void	clean_geometry(t_geom_obj *obj)
{
	if (obj == NULL)
		return ;
	matrix_free(obj->transform);
	matrix_free(obj->inv_transform);
	matrix_free(obj->t_inv_transform);
}

/**
 * @brief Frees the memory allocated for a camera object.
 *
 * @param obj The camera object to be freed.
*/
void	clean_camera(t_camera *obj)
{
	if (obj == NULL)
		return ;
	matrix_free(obj->transform);
	matrix_free(obj->inv_transform);
	matrix_free(obj->t_inv_transform);
}
