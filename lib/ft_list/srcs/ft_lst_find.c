/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:45:09 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/15 15:45:09 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* cmp_func(node_content, new_content) */
t_ftnode	*ft_lst_find(t_ftlist *lst, void *value,
	int (*cmp_func)(void *, void *))
{
	t_ftnode	*iter;

	if (lst == NULL || cmp_func == NULL)
		return (NULL);
	iter = lst->front;
	while (iter != NULL)
	{
		if (cmp_func(iter->content, value))
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}
