/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:09 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Initialize a list of intings (t_ftlist) with null
// 				pointers and size value as zero.
//
// Arguments: 'lst' is a pointer to the list to be initialized.
//
// Return value: 1 if 'lst' is NULL, 0 if success.
int	ft_lst_init(t_ftlist *lst)
{
	if (lst == NULL)
		return (1);
	lst->front = NULL;
	lst->back = NULL;
	lst->size = 0;
	return (0);
}
