/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:18:36 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:17 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Insert a node at the end (back) of a list.
//
// Arguments: 'lst' is a pointer to a list. 'node' is a pointer to
//			  the node to be added to list.
//
// Return value: Return a pointer to the inserted node, or NULL
//				if 'lst' or 'node' value is NULL.
t_ftnode	*ft_lst_push_back_node(t_ftlist *lst, t_ftnode *node)
{
	if (lst == NULL || node == NULL)
		return (NULL);
	if (lst->size == 0)
	{
		node->prev = NULL;
		lst->front = node;
	}
	else
	{
		node->prev = lst->back;
		lst->back->next = node;
	}
	node->next = NULL;
	lst->back = node;
	lst->size += 1;
	return (node);
}
