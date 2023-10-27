/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:44:21 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/15 21:38:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int	create_window(t_args *args)
{
	args->mlx_win = mlx_new_window(args->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_TITLE);
	mlx_expose_hook(args->mlx_win, refresh, args);
	mlx_hook(args->mlx_win, ON_DESTROY,
		MASK_STRUCTURE_NOTIFY, on_destroy, args);
	mlx_hook(args->mlx_win, ON_KEYDOWN, MASK_KEY_PRESS, on_key_press, args);
	mlx_loop(args->mlx);
	return (0);
}

int	on_destroy(t_args *data)
{
	mlx_loop_end(data->mlx);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->mlx_data.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	on_key_press(int keycode, t_args *data)
{
	if (keycode == KEY_ESCAPE)
	{
		on_destroy(data);
		return (0);
	}
	return (0);
}

int	refresh(t_args *args)
{
	mlx_put_image_to_window(args->mlx, args->mlx_win,
		args->mlx_data.img, 0, 0);
	return (0);
}
