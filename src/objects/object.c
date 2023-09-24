/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:38:35 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/24 07:50:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <objects.h>
#include <varray.h>
#include <projection.h>

t_err	set_object(t_obj *object, t_matrix *transform, t_material *material)
{
	object->material = *material;
	object->transform = NULL;
	object->inv_transform = NULL;
	object->t_inv_transform = NULL;
	return (set_object_transform(object, transform));
}

t_err	set_object_transform(t_obj *object, t_matrix *transform)
{
	free_obj(object);
	object->transform = transform;
	if (object->transform == NULL)
		return (ERR_ALLOC);
	object->inv_transform = matrix_inverse(transform);
	if (object->inv_transform == NULL)
		return (ERR_ALLOC);
	object->t_inv_transform = matrix_transpose(object->inv_transform);
	if (object->t_inv_transform == NULL)
		return (ERR_ALLOC);
	return (OK);
}
