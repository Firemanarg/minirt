/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:24 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:05 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Return the content of the node at an specified
//				position (index) of a list.
//
// Arguments: 'lst' is a pointer to a list. 'index' is the position of the
//				desired node from list.
//
// Return value: Pointer to content of node if success, or NULL if 'lst'
//				is NULL or the node at 'index' doesn't exist.
void	*ft_lst_get(t_ftlist *lst, int index)
{
	t_ftnode	*node;

	if (lst == NULL)
		return (NULL);
	node = ft_lst_getnode(lst, index);
	if (node == NULL)
		return (NULL);
	return (node->content);
}
