/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:58:18 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 11:47:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	is_valid_color(t_vec3 *color)
{
	if (color->x < 0 || color->x > 255)
		return (0);
	else if (color->y < 0 || color->y > 255)
		return (0);
	else if (color->z < 0 || color->z > 255)
		return (0);
	return (1);
}

int	is_valid_ratio(double ratio)
{
	return (ratio >= MIN_RATIO && ratio <= MAX_RATIO);
}

int	is_valid_fov(double fov)
{
	return (fov >= MIN_FOV && fov <= MAX_FOV);
}

int	is_valid_direction(t_vec3 *dir)
{
	if (dir->x < -1 || dir->x > 1)
		return (0);
	else if (dir->y < -1 || dir->y > 1)
		return (0);
	else if (dir->z < -1 || dir->z > 1)
		return (0);
	else if (!(dbl_abs(length(dir) - 1.0) < 1e-7))
		return (0);
	return (1);
}

int	is_str_vec3(char *str)
{
	char	**split;
	char	**iter;
	int		count;

	split = ft_split(str, ',');
	count = 0;
	iter = split;
	while (*iter)
	{
		if (!ft_str_isdouble(*iter))
			return ((long) ft_clear_arr((void **) split, free));
		count += 1;
		iter++;
	}
	ft_clear_arr((void **) split, free);
	return (count == 3);
}
