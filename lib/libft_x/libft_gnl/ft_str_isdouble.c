/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:21:32 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/07 14:21:32 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

int	ft_str_isdouble(char const *str)
{
	int	i;
	int	found_dot;
	int	has_started_digits;

	has_started_digits = 0;
	found_dot = 0;
	i = 0;
	while (ft_is_whitespace(str[i]))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		i += 1;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			has_started_digits = 1;
		if (str[i] == '.' && !found_dot && has_started_digits)
			found_dot = 1;
		else if (!ft_isdigit(str[i]))
			return (0);
		i += 1;
	}
	return (has_started_digits);
}
