/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr2hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:08:06 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:22:07 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

/*	************************************************************************* */
/*	*****************   S T A T I C   F U N C T I O N S   ******************* */
/*	************************************************************************* */

static char	*rec_hex(char *str, unsigned long nbr, char **hex_digits);

/*	************************************************************************* */
/*	*******************   I M P L E M E N T A T I O N S   ******************* */
/*	************************************************************************* */

char	*nbr2hex(unsigned long nbr, int upper)
{
	char	*hex_digits;
	char	*result;

	result = NULL;
	if (upper == 1)
		hex_digits = ft_strdup("0123456789ABCDEF");
	else
		hex_digits = ft_strdup("0123456789abcdef");
	if (!hex_digits)
		return (NULL);
	result = rec_hex(NULL, nbr, &hex_digits);
	free(hex_digits);
	hex_digits = NULL;
	return (result);
}

/*	************************************************************************* */

static char	*rec_hex(char *str, unsigned long nbr, char **hex_digits)
{
	char	*result;

	result = b_appchr(str, (*hex_digits)[nbr % 16]);
	if (!result)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	free(str);
	str = NULL;
	if (nbr / 16 == 0)
		return (result);
	return (rec_hex(result, nbr / 16, hex_digits));
}

/*	************************************************************************* */
/*	**********************   E N D   O F   C O D E   ************************ */
/*	************************************************************************* */
