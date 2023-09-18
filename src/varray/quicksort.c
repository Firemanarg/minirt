/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 03:01:33 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/18 12:17:19 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projection.h>
#include <varray.h>

static void	swap(t_isect *arr, int left, int right)
{
	t_isect	tmp;

	tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

static double	get_pivot(t_isect *arr, int left, int right)
{
	int	mid;

	mid = (left + right) / 2;
	if (arr[left].t > arr[mid].t)
		swap(arr, left, mid);
	if (arr[mid].t > arr[right].t)
		swap(arr, mid, right);
	if (arr[left].t > arr[right].t)
		swap(arr, left, right);
	swap(arr, mid, right);
	return (arr[right].t);
}

static int	partition(t_isect *arr, int left, int right, double pivot)
{
	int		i;
	int		j;

	j = left - 1;
	i = left;
	while (i <= right)
	{
		if (arr[i].t <= pivot)
		{
			++j;
			swap(arr, i, j);
		}
		++i;
	}
	return (j);
}

static void	do_quicksort(t_varray *r, int left, int right)
{
	double	pivot;
	int		mid;

	if (left >= right)
		return ;
	pivot = get_pivot(r->arr, left, right);
	mid = partition(r->arr, left, right, pivot);
	do_quicksort(r, left, mid - 1);
	do_quicksort(r, mid + 1, right);
}

void	quicksort(t_varray *r)
{
	do_quicksort(r, 0, r->length - 1);
}
