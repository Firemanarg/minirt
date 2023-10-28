/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:07 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

static char const	*ft_find_start(char const *s1, char const *set);
static char const	*ft_find_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*newstr;

	newstr = NULL;
	if (s1 != NULL)
	{
		start = ft_find_start(s1, set);
		end = ft_find_end(s1, set);
		newstr = ft_strndup(start, (end - start) + 1);
	}
	return (newstr);
}

static char const	*ft_find_start(char const *s1, char const *set)
{
	char const	*iter;

	iter = s1;
	while (*iter != '\0')
	{
		if (!ft_strchr(set, *iter))
			return (iter);
		iter++;
	}
	return (iter);
}

static char const	*ft_find_end(char const *s1, char const *set)
{
	char const	*iter;

	iter = s1 + ft_strlen(s1) - 1;
	while (iter > s1)
	{
		if (!ft_strchr(set, *iter))
			return (iter);
		iter--;
	}
	return (iter);
}
