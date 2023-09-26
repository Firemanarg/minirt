/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:18:36 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:22:07 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

int	print_hex(unsigned long h, int upper)
{
	int				len;
	char			*hex;
	unsigned int	hh;

	hh = h;
	if (upper)
		hex = nbr2hex(hh, 1);
	else
		hex = nbr2hex(hh, 0);
	if (!hex)
		return (0);
	len = (int) ft_strlen(hex);
	ft_putstr_fd(hex, 1);
	free(hex);
	hex = NULL;
	return (len);
}

/*	************************************************************************* */

int	b_print_hex(unsigned long h, int upper, char flag_chr, int width)
{
	int				len;
	char			*hex;
	unsigned int	hh;

	hh = h;
	if (upper)
		hex = nbr2hex(hh, 1);
	else
		hex = nbr2hex(hh, 0);
	if (!hex)
		return (0);
	len = (int) ft_strlen(hex);
	len += put_width_chr(width, len, flag_chr);
	ft_putstr_fd(hex, 1);
	free(hex);
	hex = NULL;
	return (len);
}

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
