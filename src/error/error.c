/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:14:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/26 22:45:43 by lsilva-q         ###   ########.fr       */
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
		"INVALID_HEIGHT", "INVALID_DIRECTION", "ERROR_DURING_RENDERING"
	};

	return (err_msg[err]);
}

int	baracapy(void)
{
	ft_putstr_fd(TXT_COLOR_YELLOW, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("                   ⣤⣄⢘⣒⣀⣀⣀⣀   \n", 1);
	ft_putstr_fd("                   ⣽⣿⣛⠛⢛⣿⣿⡿⠟⠂ \n", 1);
	ft_putstr_fd("           ⣀⣀⣀⣀⡀ ⣤⣾⣿⣿⣿⣿⣿⣿⣿⣷⣿⡆ \n", 1);
	ft_putstr_fd("      ⣀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁ \n", 1);
	ft_putstr_fd("   ⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇      \n", 1);
	ft_putstr_fd("  ⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇      \n", 1);
	ft_putstr_fd("  ⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠜       \n", 1);
	ft_putstr_fd("   ⢿⣿⣿⣿⣿⠿⠿⣿⣿⡿⢿⣿⣿⠈⣿⣿⣿⡏⣠⡴       \n", 1);
	ft_putstr_fd("  ⣠⣿⣿⣿⡿⢁⣴⣶⣄  ⠉⠉⠉ ⢻⣿⡿⢰⣿⡇       \n", 1);
	ft_putstr_fd("  ⢿⣿⠟⠋ ⠈⠛⣿⣿      ⠸⣿⡇⢸⣿⡇       \n", 1);
	ft_putstr_fd("  ⠘⣿⣄    ⠘⣿⣄      ⠘⣿⣄⠘⣿⣄      \n", 1);
	ft_putstr_fd(TXT_COLOR_BLUE, 1);
	ft_putstr_fd("  ____             ____             _ \n", 1);
	ft_putstr_fd(" |  _ \\           |  _ \\           | |\n", 1);
	ft_putstr_fd(" | |_) |_   _  ___| |_) |_   _  ___| |\n", 1);
	ft_putstr_fd(" |  _ <| | | |/ _ \\  _ <| | | |/ _ \\ |\n", 1);
	ft_putstr_fd(" | |_) | |_| |  __/ |_) | |_| |  __/_|\n", 1);
	ft_putstr_fd(" |____/ \\__, |\\___|____/ \\__, |\\___(_)\n", 1);
	ft_putstr_fd("         __/ |            __/ |       \n", 1);
	ft_putstr_fd("        |___/            |___/        \n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(TXT_COLOR_RESET, 1);
	return (0);
}

void	minirt_title(void)
{
	ft_putstr_fd(TXT_COLOR_BLUE, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("            _       _ _____ _______ \n", 1);
	ft_putstr_fd("           (_)     (_)  __ \\__   __|\n", 1);
	ft_putstr_fd("  _ __ ___  _ _ __  _| |__) | | |\n", 1);
	ft_putstr_fd(" | '_ ` _ \\| | '_ \\| |  _  /  | |\n", 1);
	ft_putstr_fd(" | | | | | | | | | | | | \\ \\  | |\n", 1);
	ft_putstr_fd(" |_| |_| |_|_|_| |_|_|_|  \\_\\ |_|\n", 1);
	ft_putstr_fd(TXT_COLOR_CYAN, 1);
	ft_putstr_fd("             by gmachado & lsilva-q\n", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(TXT_COLOR_RESET, 1);
}
