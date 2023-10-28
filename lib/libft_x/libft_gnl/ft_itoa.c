/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:14:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

/*
**	Function name:
**		> ft_count_digits
**	Parameters:
**		> n (int) : Number from which the digits will be counted
**	Description:
**		> Count how many digits the parameter n has, then return that amount
**	Return:
**		> (int). Return the amount of digits in number n
*/

static int	ft_count_digits(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len += 1;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int		len;
	unsigned int	nbr;
	char			*str;

	len = ft_count_digits(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = n * (-1);
	}
	while (nbr > 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
		len -= 1;
	}
	return (str);
}
