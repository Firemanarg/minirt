/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:40 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	len;
	size_t	index;
	char	*result;

	len = ft_strlen(str1) + ft_strlen(str2);
	if (len == 0)
		return (NULL);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (str1 && *str1)
	{
		result[index] = *str1;
		index += 1;
		str1++;
	}
	while (str2 && *str2)
	{
		result[index] = *str2;
		index += 1;
		str2++;
	}
	result[index] = '\0';
	return (result);
}
