/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:11:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 16:36:17 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

static t_list	*ft_lstget_rec(t_list *lst, int curr_index, int index);

t_list	*ft_lstget(t_list *lst, int index)
{
	return (ft_lstget_rec(lst->next, 0, index));
}

static t_list	*ft_lstget_rec(t_list *lst, int curr_index, int index)
{
	if (lst == NULL || curr_index > index)
		return (NULL);
	else if (curr_index == index)
		return (lst);
	else
		return (ft_lstget_rec(lst->next, curr_index + 1, index));
}
