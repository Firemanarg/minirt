/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:18:44 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Remove a node at an specified position (index) from a list,
//				and set it's next and prev values to NULL.
//
// Arguments: 'lst' is a pointer to a inting list. 'index' is the position
//				of the desired node to remove from list.
//
// Return value: Return a pointer to the removed (and freed) node if success,
//				otherwise return NULL (if 'lst' is NULL or empty).
void	*ft_lst_pop(t_ftlist *lst, int index)
{
	t_ftnode	*node;

	node = ft_lst_getnode(lst, index);
	return (ft_lst_pop_node(lst, node));
}
