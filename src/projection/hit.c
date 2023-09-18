/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 02:59:40 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 12:17:01 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <projection.h>
#include <varray.h>

t_isect	*hit(t_varray *r)
{
	int	idx;

	idx = first_positive(r);
	if (idx < 0)
		return (NULL);
	return (&((t_isect *)r->arr)[idx]);
}
