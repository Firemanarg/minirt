/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:18:52 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:47:37 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Remove the specified node from an inting list, and set it's
//				next and prev values to NULL.
//
// Arguments: 'lst' is a pointer to a inting list. 'node' is the desired
//				node to be removed from list.
//
// Return value: Return the content of the removed (and freed) node if success,
//				otherwise return NULL (if 'lst' is NULL or empty).
void	*ft_lst_pop_node(t_ftlist *lst, t_ftnode *node)
{
	void	*content;

	if (lst == NULL || lst->size == 0)
		return (NULL);
	if (ft_lst_getindex(lst, node) == -1)
		return (NULL);
	if (node == lst->front)
		return (ft_lst_pop_front(lst));
	else if (node == lst->back)
		return (ft_lst_pop_back(lst));
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	lst->size -= 1;
	content = node->content;
	free(node);
	return (content);
}
