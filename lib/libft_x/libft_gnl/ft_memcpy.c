/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:14:11 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*b_value_dest;
	unsigned char	*b_value_src;

	if (!dest && !src)
		return (NULL);
	b_value_dest = (unsigned char *) dest;
	b_value_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		b_value_dest[i] = b_value_src[i];
		i += 1;
	}
	return (dest);
}
