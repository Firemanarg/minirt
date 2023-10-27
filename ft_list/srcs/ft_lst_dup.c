/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:38 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:04 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Duplicate a list, generating a new one with a copy of values.
//
// Arguments: 'lst' is a pointer to the list that will be copied. 'copy_f' is
//				the copy function that will be used to generate a copy of
//				the content values (if 'copy_f' is NULL, the original
//				content values will be assigned to the new content values)
//
// Return value: A pointer to the new list if success, or NULL if the
//				operation fail.
t_ftlist	*ft_lst_dup(t_ftlist *lst, void *(*copy_f)(void *))
{
	t_ftlist	*copy;
	t_ftnode	*it;
	void		*value;

	if (lst == NULL)
		return (NULL);
	copy = malloc(sizeof(t_ftlist));
	if (ft_lst_init(copy) == 1)
		return (NULL);
	it = lst->front;
	while (it != NULL)
	{
		if (copy_f == NULL)
			value = it->content;
		else
			value = copy_f(it->content);
		if (ft_lst_push_back(copy, value) == NULL)
		{
			ft_lst_clear(copy, NULL);
			return (NULL);
		}
		it = it->next;
	}
	return (copy);
}
