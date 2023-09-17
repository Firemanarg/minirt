/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 02:59:40 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/16 22:05:22 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projection.h>
#include <v_array.h>

t_isect	*hit(t_varray *r)
{
	int	idx;

	idx = first_positive(r);
	if (idx < 0)
		return (NULL);
	return (&r->arr[idx]);
}
