/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:39:20 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/09/22 17:39:20 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

static double	get_decimal_part(const char **str);

double	ft_atod(const char *str)
{
	const char	*iter;
	double		result;
	int			sign;
	double		decimal_part;

	iter = str;
	while (ft_is_whitespace(*iter))
		iter++;
	sign = 1;
	if (*iter == '-')
		sign = -1;
	if (*iter == '-' || *iter == '+')
		iter++;
	result = get_decimal_part(&iter);
	if (*iter == '.')
		iter++;
	else if (!ft_isdigit(*iter))
		return (result * sign);
	decimal_part = get_decimal_part(&iter);
	while (decimal_part >= 1)
		decimal_part /= 10;
	result += decimal_part;
	return (result * sign);
}

static double	get_decimal_part(const char **iter)
{
	double		result;

	result = 0;
	while (ft_isdigit(**iter))
	{
		result = result * 10 + (**iter - '0');
		(*iter)++;
	}
	return (result);
}
