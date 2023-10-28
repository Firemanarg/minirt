/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:24 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:08 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Return a node at an specified position (index) of a list.
//
// Arguments: 'lst' is a pointer to a list. 'index' is the position of the
//				desired node from list.
//
// Return value: Pointer to node if success, or NULL if 'lst' is NULL
//				or 'index' value is invalid (0 < index or index >= list size).
static int	get_direction(t_ftlist *lst, int index);

t_ftnode	*ft_lst_getnode(t_ftlist *lst, int index)
{
	t_ftnode	*node;
	int			count;
	int			direction;

	if (lst == NULL || lst->size == 0)
		return (NULL);
	if (index < 0 || index >= lst->size)
		return (NULL);
	direction = get_direction(lst, index);
	count = (lst->size - 1) * (direction == -1);
	if (direction == 1)
		node = lst->front;
	else
		node = lst->back;
	while (count != index)
	{
		if (direction == 1)
			node = node->next;
		else
			node = node->prev;
		count += direction;
	}
	return (node);
}

static int	get_direction(t_ftlist *lst, int index)
{
	if (index < (lst->size / 2))
		return (1);
	return (-1);
}
