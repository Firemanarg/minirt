/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 04:51:47 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/23 01:31:41 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <objects.h>

void	free_obj(t_obj *obj)
{
	free(obj->transform);
	free(obj->inv_transform);
	free(obj->t_inv_transform);
}
