/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:44:21 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/09 00:04:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphics.h>

int	close_graphics(t_args *data)
{
	printf("Bye bye :D\n");
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_loop_end(data->mlx);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	on_destroy(t_args *data)
{
	close_graphics(data);
	return (0);
}

int	on_key_press(int keycode, t_args *data)
{
	if (keycode == KEY_ESCAPE)
	{
		close_graphics(data);
		return (0);
	}
	else
		printf("Key pressed: %i\n", keycode);
	return (0);
}

int	create_window(t_args *args)
{
	args->mlx = mlx_init();
	args->mlx_win = mlx_new_window(args->mlx, 600, 400, "MiniRT");
	mlx_hook(args->mlx_win, ON_DESTROY,
		MASK_STRUCTURE_NOTIFY, on_destroy, args);
	mlx_hook(args->mlx_win, ON_KEYDOWN, MASK_KEY_PRESS, on_key_press, args);
	mlx_loop(args->mlx);
	return (0);
}
