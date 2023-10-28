/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_ord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:46:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/14 15:46:35 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* lesser_func must return if val1 < val2*/
/* lesser_func(node_content, new_content) */
t_ftnode	*ft_lst_push_ord(t_ftlist *lst, void *content,
	int (*lesser_func)(void *, void *))
{
	t_ftnode	*node;
	t_ftnode	*iter;

	if (lst == NULL || lesser_func == NULL)
		return (NULL);
	node = ft_node_new(content);
	iter = lst->front;
	while (iter != NULL)
	{
		if (!lesser_func(iter->content, content))
		{
			node->next = iter;
			node->prev = iter->prev;
			iter->prev = node;
			if (node->prev != NULL)
				(node->prev)->next = node;
			if (lst->front == iter)
				lst->front = node;
			lst->size += 1;
			return (node);
		}
		iter = iter->next;
	}
	return (ft_lst_push_back_node(lst, node));
}
