/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:24:34 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/27 17:24:34 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* Func prototype:
	> void func(void *content, size_t index, int is_first, int is_last);
*/
void	ft_lst_func_apply(t_ftlist *lst,
	void (*func)(void *, size_t, int, int))
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
		func(iter->content, index, is_first, is_last);
		iter = iter->next;
		index += 1;
	}
}
