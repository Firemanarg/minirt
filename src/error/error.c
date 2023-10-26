/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:14:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/26 17:37:26 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static char	*get_err_msg(t_err err);

void	print_msg(char *context, char *msg, char *color)
{
	ft_putstr_fd(TXT_COLOR_RESET, 1);
	if (color)
		ft_putstr_fd(color, 1);
	if (context)
	{
		ft_putstr_fd("[", 1);
		ft_putstr_fd(context, 1);
		ft_putstr_fd("]: ", 1);
	}
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(TXT_COLOR_RESET, 1);
}

void	print_error(char *context, t_err err, int line)
{
	ft_putstr_fd(TXT_COLOR_RED, 2);
	if (context)
	{
		ft_putstr_fd("[", 2);
		ft_putstr_fd(context, 2);
		ft_putstr_fd("]: ", 2);
	}
	ft_putstr_fd("Error", 2);
	if (line > 0)
	{
		ft_putstr_fd(" at line ", 2);
		ft_putnbr_fd(line, 2);
	}
	ft_putstr_fd(": (code ", 2);
	ft_putnbr_fd(err, 2);
	ft_putstr_fd(") ", 2);
	ft_putstr_fd(get_err_msg(err), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(TXT_COLOR_RESET, 2);
}

static char	*get_err_msg(t_err err)
{
	static char	*err_msg[] = {
		"OK", "ERR_ALLOC", "INVALID_VEC3", "INVALID_ARG", "INVALID_TYPE",
		"INVALID_ARG_COUNT", "INVALID_RATIO", "INVALID_COLOR",
		"ERR_PARSING_FILE", "ERR_WRONG_USAGE", "TOO_MANY_AMBIENT_LIGHTS",
		"TOO_MANY_CAMERAS", "TOO_MANY_LIGHTS", "MISSING_AMBIENT_LIGHT",
		"MISSING_CAMERA", "MISSING_LIGHT", "INVALID_DIAMETER", "INVALID_FOV",
		"INVALID_HEIGHT", "INVALID_DIRECTION"
	};

	return (err_msg[err]);
}
