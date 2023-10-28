/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:55:26 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:25 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Free a node.
//
// Arguments: 'node' is the target node to be freed.
//
// Return value: Void function.
void	ft_node_free(t_ftnode *node)
{
	if (node != NULL)
		free(node);
}
