/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:14:01 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*newstr;
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		newstr = ft_calloc(len + 2, sizeof(char));
		if (!newstr)
			return ;
		ft_strlcpy(newstr, s, len + 2);
		newstr[len] = '\n';
		newstr[len + 1] = '\0';
		ft_putstr_fd(newstr, fd);
		free(newstr);
	}
}
