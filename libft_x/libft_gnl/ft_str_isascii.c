/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:36:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 16:35:33 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

int	ft_str_isascii(char const *str)
{
	const char	*chr;

	if (str == NULL)
		return (0);
	chr = str;
	while (*chr != '\0')
	{
		if (!ft_isascii((int) *chr))
			return (0);
		chr++;
	}
	return (1);
}
