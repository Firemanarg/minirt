/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:08 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:10 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Remove a node at the end (back) from an inting list, and set
//				it's next and prev values to NULL.
//
// Arguments: 'lst' is a pointer to a list.
//
// Return value: Return the content of the removed (and freed) node if success,
//				otherwise return NULL (if 'lst' is NULL or empty).
void	*ft_lst_pop_back(t_ftlist *lst)
{
	t_ftnode	*node;
	void		*content;

	if (lst == NULL || lst->size == 0)
		return (NULL);
	node = lst->back;
	lst->back = node->prev;
	if (node->prev)
		node->prev->next = NULL;
	else
		lst->front = NULL;
	node->next = NULL;
	node->prev = NULL;
	lst->size -= 1;
	content = node->content;
	free(node);
	return (content);
}
