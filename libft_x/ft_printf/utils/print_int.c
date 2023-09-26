/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:18:32 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:22:07 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

int	print_int(int nbr)
{
	char	*str;
	int		len;

	str = ft_ltoa(nbr);
	if (!str)
		return (0);
	len = (int) ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	return (len);
}

/*	************************************************************************* */

int	print_uint(unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_ltoa(nbr);
	if (!str)
		return (0);
	len = (int) ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	return (len);
}

/*	************************************************************************* */

int	b_print_int(int nbr, char flag_chr, int width)
{
	char	*str;
	int		len;

	str = ft_ltoa(nbr);
	if (!str)
		return (0);
	len = (int) ft_strlen(str);
	if (nbr < 0 && flag_chr == '0')
		ft_putchar_fd('-', 1);
	len += put_width_chr(width, len, flag_chr);
	if (nbr < 0 && flag_chr == '0')
		ft_putstr_fd(str + 1, 1);
	else
		ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	return (len);
}

/*	************************************************************************* */

int	b_print_uint(unsigned int nbr, char flag_chr, int width)
{
	char	*str;
	int		len;

	str = ft_ltoa(nbr);
	if (!str)
		return (0);
	len = (int) ft_strlen(str);
	len += put_width_chr(width, len, flag_chr);
	ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	return (len);
}

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
