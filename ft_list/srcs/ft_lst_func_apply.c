/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:24:34 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/21 16:40:33 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* Func prototype:
	> void func(void *content, size_t index, int is_first, int is_last);
*/

/**
 * @brief Applies a function to each node of the list, then replaces the
 * content of the node with the return of the function. To avoid memory leaks,
 * the function must free the memory of the old content and return the new
 * content. If you don't want to change the content of the node, just return
 * the same content you received.
 * @param lst The list to apply the function.
 * @param func The function to apply `void *func(void *content, size_t index,
 * int is_first, int is_last)`. Receives the content of the node, the index of
 * the node, a flag indicating if the node is the first of the list and a flag
 * indicating if the node is the last of the list. The function must return the
 * new content of the node.
 * @return `void`
*/
void	ft_lst_func_apply(t_ftlist *lst,
	void *(*func)(void *, size_t, int, int))
{
	t_ftnode	*iter;
	size_t		index;
	int			is_first;
	int			is_last;

	if (lst == NULL || func == NULL)
		return ;
	index = 0;
	iter = lst->front;
	while (iter != NULL)
	{
		is_first = (iter == lst->front);
		is_last = (iter == lst->back);
		iter->content = func(iter->content, index, is_first, is_last);
		iter = iter->next;
		index += 1;
	}
}
