/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:14:09 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*b_value_dest;
	unsigned char	*b_value_src;

	if (!dest && !src)
		return (NULL);
	b_value_dest = (unsigned char *) dest;
	b_value_src = (unsigned char *) src;
	if ((dest >= src) && (dest <= (src + (n - 1))))
	{
		i = 0;
		while (i < n)
		{
			b_value_dest[n - 1 - i] = b_value_src[n - 1 - i];
			i += 1;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
