/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:00:32 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:26 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Allocate a new node (t_ftnode) with null pointers
//				and argument content.
//
// Arguments: 'content' is a pointer to the content of the new node.
//
// Return value: NULL if allocation fails, otherwise return a pointer
// 				 to the allocated node.
t_ftnode	*ft_node_new(void *content)
{
	t_ftnode	*node;

	node = malloc(sizeof(t_ftnode));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->content = content;
	return (node);
}
