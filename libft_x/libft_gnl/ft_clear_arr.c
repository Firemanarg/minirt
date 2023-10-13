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
 * @brief Clears an array (last value must be NULL) and returns NULL.
 *
 * @param arr The array to be cleaned.
 *
 * @return NULL.
*/
void	*ft_clear_arr(void **arr)
{
	void	**iter;

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
