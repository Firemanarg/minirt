/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:49 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;

	if (s == NULL)
		return (NULL);
	cc = c;
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *) s);
		s++;
	}
	if (cc == '\0')
		return ((char *) s);
	return (NULL);
}
