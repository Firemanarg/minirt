/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:20 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	ucs1 = (unsigned char *) s1;
	ucs2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ucs1[i] && (ucs1[i] == ucs2[i]) && (i < n - 1))
		i += 1;
	return (ucs1[i] - ucs2[i]);
}
