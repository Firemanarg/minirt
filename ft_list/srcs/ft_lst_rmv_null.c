/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rmv_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:05:46 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/21 23:35:00 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @brief Removes all nodes with NULL content from the list.
 *
 * @param lst The list to remove the nodes.
*/
void	ft_lst_rmv_null(t_ftlist *lst)
{
	t_ftnode	*iter;
	t_ftnode	*next;

	if (lst == NULL)
		return ;
	iter = lst->front;
	while (iter != NULL)
	{
		next = iter->next;
		if (iter->content == NULL)
			free(ft_lst_pop_node(lst, iter));
		iter = next;
	}
}
