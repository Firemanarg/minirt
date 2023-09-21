/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:18:55 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/21 04:06:40 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphics.h>
#include <objects.h>

void	init_args(t_args *args, int width, int height)
{
	args->mlx = mlx_init();
	args->mlx_win = mlx_new_window(args->mlx, width, height, "MiniRT");
	args->mlx_data.img = mlx_new_image(args->mlx, width, height);
	args->mlx_data.addr = mlx_get_data_addr(args->mlx_data.img,
			&args->mlx_data.bits_per_pixel,
			&args->mlx_data.line_length,
			&args->mlx_data.endian);
}

void	ft_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	void	*dst;

	dst = mlx_data->addr + (y * mlx_data->line_length
			+ x * (mlx_data->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

int	convert_color(t_color *minirt_color)
{
	int	t;

	t = 0;
	return ((t << 24)
		+ ((int)(minirt_color->r * 255.0) << 16)
		+ ((int)(minirt_color->g * 255.0) << 8)
		+ (int)(minirt_color->b * 255.0));
}
