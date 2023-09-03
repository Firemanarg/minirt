/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:55:06 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/01 00:55:58 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

// From https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
