/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:14:59 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/09/24 15:30:44 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

/*
**	Function name:
**		> ft_skip_whitespaces
**	Parameters:
**		> i (size_t) : Start index
**		> nptr (const char *) : String to be converted to integer
**	Description:
**		> Skips whitespaces, starting at position i and returning when
**			non-whitespace character is found
**	Return:
**		> (size_t). Index of first non-whitespace character found.
*/

static size_t	ft_skip_whitespaces(size_t i, const char *nptr)
{
	while (ft_is_whitespace(nptr[i]))
		i += 1;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		nbr;
	int		signal;

	i = 0;
	nbr = 0;
	i = ft_skip_whitespaces(i, nptr);
	signal = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = -1;
		i += 1;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i += 1;
	}
	nbr *= signal;
	return (nbr);
}
