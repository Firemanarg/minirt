/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:14:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (*lst == NULL)
		{
			new->next = NULL;
			*lst = new;
		}
		else
		{
			new->next = *lst;
			*lst = new;
		}
	}
}
