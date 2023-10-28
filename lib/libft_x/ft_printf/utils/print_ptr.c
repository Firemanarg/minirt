/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:18:27 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:22:07 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

int	print_ptr(void *ptr)
{
	unsigned long	address;
	char			*hex_address;
	int				len;

	if (!ptr)
		return (print_str("(nil)"));
	address = (unsigned long) ptr;
	hex_address = nbr2hex(address, 0);
	if (!hex_address)
		return (0);
	len = (int) ft_strlen(hex_address);
	len += print_str("0x");
	ft_putstr_fd(hex_address, 1);
	free(hex_address);
	hex_address = NULL;
	return (len);
}

/*	************************************************************************* */

int	b_print_ptr(void *ptr, char flag_chr, int width)
{
	unsigned long	address;
	char			*hex_address;
	int				len;

	if (!ptr)
		hex_address = ft_strdup("(nil)");
	else
	{
		address = (unsigned long) ptr;
		hex_address = nbr2hex(address, 0);
	}
	if (!hex_address)
		return (0);
	len = (int) ft_strlen(hex_address);
	if (flag_chr == '0' && ptr)
		print_str("0x");
	if (ptr)
		len += 2;
	len += put_width_chr(width, len, flag_chr);
	if (flag_chr == ' ' && ptr)
		print_str("0x");
	ft_putstr_fd(hex_address, 1);
	free(hex_address);
	hex_address = NULL;
	return (len);
}

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
