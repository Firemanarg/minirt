/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:18:36 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:18 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Insert a node at the end (back) of a list.
//
// Arguments: 'lst' is a pointer to a list. 'content' is a pointer to
//			  the content of the new node.
//
// Return value: Return a pointer to the inserted node, or NULL
//				if 'lst' or 'node' value is NULL.
t_ftnode	*ft_lst_push_back(t_ftlist *lst, void *content)
{
	t_ftnode	*node;

	if (lst == NULL)
		return (NULL);
	node = ft_node_new(content);
	return (ft_lst_push_back_node(lst, node));
}
