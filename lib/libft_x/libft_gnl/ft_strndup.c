/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:47 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*new_str;

	if (str == NULL || n == 0)
		return (NULL);
	if (ft_strlen(str) == 0)
		return (NULL);
	new_str = malloc((n + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_str[i] = str[i];
		i += 1;
	}
	new_str[n] = '\0';
	return (new_str);
}
