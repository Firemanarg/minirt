/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:24 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:22 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Set the content value of the node at an specified
//				position (index) in a list.
//
// Arguments: 'lst' is a pointer to a list. 'index' is the position of the
//				desired node from list. 'content' is the new value to be
//				assigned to the node content.
//
// Return value: 0 (zero) if success, or 1 if 'lst' is NULL or the node at
//				'index' doesn't exist.
int	ft_lst_set(t_ftlist *lst, int index, void *content)
{
	t_ftnode	*node;

	if (lst == NULL)
		return (1);
	node = ft_lst_getnode(lst, index);
	if (node == NULL)
		return (1);
	node->content = content;
	return (0);
}
