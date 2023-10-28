/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:21 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Construct and insert a node at an specified position (index)
//				of a list.
//
// Arguments: 'lst' is a pointer to a list. 'index' is the desired
//				position to insert node. 'content' is a pointer to
//			  the content of the node.
//
// Return value: Return a pointer to the inserted node, or NULL
//				if 'lst' is NULL or the operation fail.
t_ftnode	*ft_lst_push(t_ftlist *lst, int index, void *content)
{
	t_ftnode	*node;

	node = ft_node_new(content);
	if (node == NULL)
		return (NULL);
	return (ft_lst_push_node(lst, index, node));
}
