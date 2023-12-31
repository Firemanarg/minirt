/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:18:55 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:44:38 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_bonus.h"
#include "objects_bonus.h"

void	init_args(t_args *args)
{
	args->mlx = mlx_init();
	args->mlx_data.img = mlx_new_image(args->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	args->mlx_data.addr = mlx_get_data_addr(args->mlx_data.img,
			&args->mlx_data.bits_per_pixel,
			&args->mlx_data.line_length,
			&args->mlx_data.endian);
}

void	ft_pixel_put(t_mlx_data *mlx_data, int x, int y, t_color *minirt_color)
{
	void	*dst;

	dst = mlx_data->addr + (y * mlx_data->line_length
			+ x * (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = convert_color(minirt_color);
}

static unsigned int	get_clamped_color(double color)
{
	if (color >= 1.0)
		return (255);
	if (color <= 0.0)
		return (0);
	return ((unsigned int)(color * 255.0));
}

unsigned int	convert_color(t_color *minirt_color)
{
	return ((get_clamped_color(minirt_color->r) << 16)
		+ (get_clamped_color(minirt_color->g) << 8)
		+ get_clamped_color(minirt_color->b));
}
