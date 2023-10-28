/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:59 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

static void	ft_putnbr_rec(unsigned int n, int *fd, int mult)
{
	char			c;
	unsigned int	tmp;

	if (mult > 0)
	{
		c = '0' + (n / mult);
		write(*fd, &c, 1);
		tmp = n / mult;
		tmp *= mult;
		ft_putnbr_rec((n - tmp), fd, mult / 10);
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	long			mult;
	unsigned int	nbr;

	mult = 1;
	while (n / (mult * 10) != 0)
		mult *= 10;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	ft_putnbr_rec(nbr, &fd, mult);
}
