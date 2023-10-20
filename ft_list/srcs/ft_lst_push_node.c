/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:18:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:20 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Insert a node at an specified position (index) of a list.
//
// Arguments: 'lst' is a pointer to a list. 'node' is a pointer to the desired
//				node to be inserted. 'index' is the desired position
//				to insert node.
//
// Return value: Return a pointer to the inserted node, or NULL
//				if 'lst' or 'node' value is NULL.
t_ftnode	*ft_lst_push_node(t_ftlist *lst, int index, t_ftnode *node)
{
	t_ftnode	*tmp;

	if (lst == NULL || node == NULL || index < 0 || index > lst->size)
		return (NULL);
	if (index == 0)
		return (ft_lst_push_front_node(lst, node));
	else if (index == lst->size)
		return (ft_lst_push_back_node(lst, node));
	tmp = ft_lst_getnode(lst, index);
	if (tmp == NULL)
		return (NULL);
	node->next = tmp;
	node->prev = tmp->prev;
	tmp->prev->next = node;
	tmp->prev = node;
	lst->size += 1;
	return (node);
}
