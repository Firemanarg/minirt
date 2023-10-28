/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:18:51 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 11:44:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"

static void	print_context(char *context);

void	print_progress(int progress, int total, char *context)
{
	static int	max_progress = 0;
	double		percentage;
	int			i;

	ft_putstr_fd("\r"TXT_COLOR_CYAN""TERM_HIDE_CURSOR, 1);
	if (total != 0 && total > max_progress)
		max_progress = total;
	if (context)
		print_context(context);
	ft_putstr_fd("Progress: [", 1);
	percentage = (double) progress / (double) max_progress;
	i = 0;
	while (i < PROGRESS_BAR_SIZE)
	{
		if (percentage >= (double) i / (double) PROGRESS_BAR_SIZE)
			ft_putchar_fd('#', 1);
		else
			ft_putchar_fd('-', 1);
		i += 1;
	}
	ft_putstr_fd("] ", 1);
	ft_putnbr_fd((int)(percentage * 100), 1);
	ft_putstr_fd("%"TXT_COLOR_RESET, 1);
	if (percentage >= 1.0)
		ft_putstr_fd(TERM_SHOW_CURSOR"\n", 1);
}

static void	print_context(char *context)
{
	if (context)
	{
		ft_putstr_fd("[", 1);
		ft_putstr_fd(context, 1);
		ft_putstr_fd("]: ", 1);
	}
}
