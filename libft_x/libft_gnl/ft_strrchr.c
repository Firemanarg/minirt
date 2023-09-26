/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:11 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;
	unsigned char	cc;
	char			*cs;

	cc = c;
	last = NULL;
	cs = (char *) s;
	while (*cs != '\0')
	{
		if (*cs == cc)
			last = cs;
		cs++;
	}
	if (cc == '\0')
		last = cs;
	return (last);
}
