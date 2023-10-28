/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:24:43 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/13 11:24:43 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_lst_last(t_ftlist *lst)
{
	if (lst == NULL || lst->back == NULL)
		return (NULL);
	return (lst->back->content);
}
