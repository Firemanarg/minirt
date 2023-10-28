/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:00:32 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:11 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Remove a node at the begin (front) from an inting list, and set
//				it's next and prev values to NULL.
//
// Arguments: 'lst' is a pointer to a inting list.
//
// Return value: Return the content of the removed (and freed) node if success,
//				otherwise return NULL (if 'lst' is NULL or empty).
void	*ft_lst_pop_front(t_ftlist *lst)
{
	t_ftnode	*node;
	void		*content;

	if (lst == NULL || lst->size == 0)
		return (NULL);
	node = lst->front;
	lst->front = node->next;
	if (node->next)
		node->next->prev = NULL;
	else
		lst->back = NULL;
	node->next = NULL;
	node->prev = NULL;
	lst->size -= 1;
	content = node->content;
	free(node);
	return (content);
}
