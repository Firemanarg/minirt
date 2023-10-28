/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:04 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;
	size_t	subs_len;

	if (s)
	{
		s_len = ft_strlen(s);
		subs_len = len;
		if (start >= s_len)
			return (ft_strdup(""));
		else if (start + len >= s_len)
			subs_len = s_len - start;
		subs = ft_calloc(subs_len + 1, sizeof(char));
		if (!subs)
			return (NULL);
		ft_strlcpy(subs, (s + start), subs_len + 1);
		return (subs);
	}
	return (NULL);
}
