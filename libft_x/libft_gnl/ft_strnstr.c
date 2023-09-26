/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	if (*little == '\0')
		return ((char *) big);
	else if (len > 0 && *big)
	{
		little_len = ft_strlen(little);
		i = 0;
		while (i < len)
		{
			if (little_len + i > len)
				break ;
			if (ft_strncmp((big + i), (little), little_len) == 0)
				return ((char *)(big + i));
			i += 1;
		}
	}
	return (NULL);
}
