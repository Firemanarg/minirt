/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:59:04 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/09/26 15:59:04 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

/**
 * @brief Clears a string array (last str must be NULL) and returns NULL.
 *
 * @param arr The string array to be cleared.
 *
 * @return NULL.
*/
void	*ft_clear_strarr(char **arr)
{
	char	**iter;

	iter = arr;
	while (*iter)
	{
		free(*iter);
		iter++;
	}
	free(arr);
	iter = NULL;
	return (NULL);
}
