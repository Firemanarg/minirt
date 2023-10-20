/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:26:07 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/13 11:26:07 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_lst_first(t_ftlist *lst)
{
	if (lst == NULL || lst->front == NULL)
		return (NULL);
	return (lst->front->content);
}
