/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:14:14 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uns_chr1;
	unsigned char	*uns_chr2;

	uns_chr1 = (unsigned char *) s1;
	uns_chr2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (uns_chr1[i] != uns_chr2[i])
			return (uns_chr1[i] - uns_chr2[i]);
		i += 1;
	}
	return (0);
}
