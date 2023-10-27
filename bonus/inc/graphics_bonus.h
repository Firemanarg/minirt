/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:24:32 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:44:17 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_BONUS_H
# define GRAPHICS_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include "objects_bonus.h"

# define WINDOW_TITLE "miniRT"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_mlx_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_args
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_data	mlx_data;
	t_scene		*scene;
}	t_args;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	KEY_ESCAPE = 65307,
	X_BUTTON = 17
};

enum {
	MASK_KEY_PRESS = 1L<<0,
	MASK_KEY_RELEASE = 1L<<1,
	MASK_STRUCTURE_NOTIFY = 1L<<17
};

// mlx_utils.c
void			init_args(t_args *args);
void			ft_pixel_put(t_mlx_data *mlx_data, int x, int y,
					t_color *minirt_color);
unsigned int	convert_color(t_color *minirt_color);

// window.c
int				create_window(t_args *args);
int				on_key_press(int keycode, t_args *data);
int				on_destroy(t_args *data);
int				refresh(t_args *args);

#endif
