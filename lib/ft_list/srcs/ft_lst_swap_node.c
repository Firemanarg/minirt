/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:00:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:23 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	swap_nodes(t_ftnode *node1, t_ftnode *node2);

// Description: Swap two nodes, specified by index.
//
// Arguments: 'lst' is a pointer to a inting list. 'index1' and 'index2'
//				are the desired positions of nodes to be swapped.
//
// Return value: 1 if 'lst' is NULL or any of indexes is invalid.
//				Return 0 if success.
int	ft_lst_swap_node(t_ftlist *lst, int index1, int index2)
{
	t_ftnode	*node1;
	t_ftnode	*node2;

	node1 = ft_lst_getnode(lst, index1);
	node2 = ft_lst_getnode(lst, index2);
	if (node1 == NULL || node2 == NULL)
		return (1);
	if (index1 == index2)
		return (0);
	if (lst->front == node1)
		lst->front = node2;
	else if (lst->front == node2)
		lst->front = node1;
	if (lst->back == node1)
		lst->back = node2;
	else if (lst->back == node2)
		lst->back = node1;
	swap_nodes(node1, node2);
	return (0);
}

static void	swap_nodes(t_ftnode *node1, t_ftnode *node2)
{
	t_ftnode	tmp;

	tmp.next = node1->next;
	tmp.prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;
	if (node1->next)
		node1->next->prev = node2;
	node1->next = node2->next;
	node1->prev = node2->prev;
	if (node2->prev)
		node2->prev->next = node1;
	if (node2->next)
		node2->next->prev = node1;
	node2->next = tmp.next;
	node2->prev = tmp.prev;
	tmp.next = NULL;
	tmp.prev = NULL;
}
