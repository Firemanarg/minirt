/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:32 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:06 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Return the index of a node in a list.
//
// Arguments: 'lst' is a pointer to a list. 'node' is a pointer to a node.
//
// Return value: -1 if 'lst' or 'node' value is NULL, or if node does'nt belong
//				to 'lst'. If success, return the index of the node.
int	ft_lst_getindex(t_ftlist *lst, t_ftnode *node)
{
	t_ftnode	*tmp;
	int			index;

	if (lst == NULL || node == NULL || lst->size == 0)
		return (-1);
	if (node == lst->front)
		return (0);
	else if (node == lst->back)
		return (lst->size - 1);
	tmp = lst->front;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp == node)
			return (index);
		index += 1;
		tmp = tmp->next;
	}
	return (-1);
}
