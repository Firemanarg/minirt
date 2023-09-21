/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 03:47:13 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/21 03:38:59 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projection.h>
#include <graphics.h>
#include <varray.h>

t_varray	*new_array(int initial_capacity)
{
	t_varray	*r;

	r = malloc(sizeof(*r));
	r->capacity = initial_capacity;
	r->length = 0;
	r->arr = malloc(sizeof(t_isect) * initial_capacity);
	return (r);
}

t_err	resize_array(t_varray *r, int new_capacity)
{
	t_isect	*new_arr;
	int		idx;

	new_arr = malloc(sizeof(t_isect) * new_capacity);
	if (!new_arr)
	{
		free(r->arr);
		free(r);
		return (ERR_ALLOC);
	}
	idx = r->capacity;
	while (--idx >= 0)
		new_arr[idx] = ((t_isect *)r->arr)[idx];
	r->capacity = new_capacity;
	free(r->arr);
	r->arr = new_arr;
	return (OK);
}

t_err	insert_into_array(t_varray *r, double t, t_obj *obj)
{
	if (r->length == r->capacity)
	{
		if (resize_array(r, 2 * r->capacity))
			return (ERR_ALLOC);
	}
	((t_isect *)r->arr)[r->length].obj = obj;
	((t_isect *)r->arr)[r->length++].t = t;
	return (OK);
}

void	free_array(t_varray *r)
{
	free(r->arr);
	free(r);
}

void	reset_array(t_varray *r)
{
	r->length = 0;
}
