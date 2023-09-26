/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:05:48 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/10 13:05:48 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const char	*iter1;
	const char	*iter2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	iter1 = s1;
	iter2 = s2;
	while (*iter1 != '\0' && *iter2 != '\0')
	{
		if (*iter1 != *iter2)
			break ;
		iter1++;
		iter2++;
	}
	return (*iter1 - *iter2);
}
