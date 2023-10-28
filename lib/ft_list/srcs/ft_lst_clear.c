/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:43 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:02 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Clear a list, freeing all nodes and their content.
//
// Arguments: 'lst' is the target list to be cleaned. f is the function to
//				be called to clean the nodes content, or NULL to keep content.
//
// Return value: Void function.
void	ft_lst_clear(t_ftlist *lst, void (*f)(void *))
{
	t_ftnode	*node;
	t_ftnode	*tmp;

	node = lst->front;
	while (node != NULL)
	{
		tmp = node->next;
		if (f != NULL)
			f(node->content);
		ft_node_free(node);
		node = tmp;
	}
	lst->front = NULL;
	lst->back = NULL;
	lst->size = 0;
}
