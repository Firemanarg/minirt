/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_toarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:57:29 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:24 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
	Description: Allocates a new array with size of the list, and the nodes
	contents as array values.

	Arguments: 'lst' is a pointer to a list.

	Return value: Return a pointer to the created array if success, or NULL
	if 'lst' is NULL or allocation fails. If list is empty, return value
	is an empty array
*/
void	**ft_lst_toarray(t_ftlist *lst)
{
	t_ftnode	*it;
	void		**array;
	int			i;

	if (lst == NULL)
		return (NULL);
	array = malloc(sizeof(void *) * (lst->size + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	it = lst->front;
	while (it != NULL)
	{
		array[i] = it->content;
		it = it->next;
		i += 1;
	}
	array[i] = NULL;
	return (array);
}
