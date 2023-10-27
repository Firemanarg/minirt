/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 02:59:40 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:47:49 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "projection_bonus.h"

t_isect	*hit(t_varray *r)
{
	int	idx;

	idx = first_positive(r);
	if (idx < 0)
		return (NULL);
	return (&((t_isect *)r->arr)[idx]);
}
