/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:53:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/15 03:24:04 by lsilva-q         ###   ########.fr       */
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
	if (obj->type == CAMERA || obj->type == SPHERE || obj->type == CYLINDER
		|| obj->type == PLANE)
	{
		matrix_free(((t_geom_obj *) obj)->transform);
		matrix_free(((t_geom_obj *) obj)->inv_transform);
		matrix_free(((t_geom_obj *) obj)->t_inv_transform);
	}
}
