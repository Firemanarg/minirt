/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:18:27 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:19 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Insert a node at the begin (front) of a list.
//
// Arguments: 'lst' is a pointer to a list. 'node' is a pointer to
//			  the node to be added to list.
//
// Return value: Return a pointer to the inserted node, or NULL
//				if 'lst' or 'node' value is NULL.
t_ftnode	*ft_lst_push_front_node(t_ftlist *lst, t_ftnode *node)
{
	if (lst == NULL || node == NULL)
		return (NULL);
	if (lst->size == 0)
	{
		node->next = NULL;
		lst->back = node;
	}
	else
	{
		node->next = lst->front;
		lst->front->prev = node;
	}
	node->prev = NULL;
	lst->front = node;
	lst->size += 1;
	return (node);
}
