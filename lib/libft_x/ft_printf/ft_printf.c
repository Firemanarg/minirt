/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:29:06 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/18 03:29:45 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

static int	is_valid_type(char type);
static int	print_arg(va_list args, char chr, int w, char type);
static char	get_flag_chr(const char **str);
static int	get_width(const char **str);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_len;
	char	flag_chr;
	int		width;

	printed_len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str != '%')
			printed_len += print_chr(*str);
		else
		{
			str++;
			flag_chr = get_flag_chr(&str);
			width = get_width(&str);
			if (is_valid_type(*str))
				printed_len += print_arg(args, flag_chr, width, *str);
			else
				break ;
		}
		str++;
	}
	va_end(args);
	return (printed_len);
}

static int	is_valid_type(char type)
{
	int		i;
	char	*valid_types;
	int		len;
	int		result;

	valid_types = ft_strdup("cspdiuxX%");
	if (!valid_types)
		return (0);
	len = (int) ft_strlen(valid_types);
	result = 0;
	i = 0;
	while (i < len)
	{
		if (type == valid_types[i])
		{
			result = 1;
			break ;
		}
		i += 1;
	}
	free(valid_types);
	valid_types = NULL;
	return (result);
}

static int	print_arg(va_list args, char chr, int w, char type)
{
	if (type == 'c')
		return (b_print_chr(va_arg(args, int), w));
	else if (type == 's')
		return (b_print_str(va_arg(args, char *), w));
	else if (type == 'p')
		return (b_print_ptr(va_arg(args, void *), chr, w));
	else if (type == 'd')
		return (b_print_int(va_arg(args, int), chr, w));
	else if (type == 'i')
		return (b_print_int(va_arg(args, int), chr, w));
	else if (type == 'u')
		return (b_print_uint(va_arg(args, unsigned int), chr, w));
	else if (type == 'x')
		return (b_print_hex(va_arg(args, int), 0, chr, w));
	else if (type == 'X')
		return (b_print_hex(va_arg(args, int), 1, chr, w));
	else if (type == '%')
		return (b_print_chr('%', w));
	return (0);
}

static char	get_flag_chr(const char **str)
{
	char	flag_chr;

	flag_chr = ' ';
	while (ft_strchr("-0.# +", **str))
	{
		if (**str == '0')
			flag_chr = '0';
		(*str)++;
	}
	return (flag_chr);
}

static int	get_width(const char **str)
{
	int	width;

	width = 0;
	while (ft_isdigit(**str))
	{
		width *= 10;
		width += (**str - '0');
		(*str)++;
	}
	return (width);
}
