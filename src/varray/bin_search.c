/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:19:22 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 14:39:52 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

int	bin_search_gt(t_varray *r, double target, int left, int right)
{
	int	mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if ((((t_isect *)r->arr)[mid]).t <= target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

int	first_positive(t_varray *r)
{
	int	idx;

	idx = bin_search_gt(r, 0, 0, r->length - 1);
	if (idx < 0 || idx >= r->length)
		return (-1);
	return (idx);
}
