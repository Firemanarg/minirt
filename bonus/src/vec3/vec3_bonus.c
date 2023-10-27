/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:37:49 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:48:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_bonus.h"

void	set_vec3(double x, double y, double z, t_vec3 *t)
{
	t->x = x;
	t->y = y;
	t->z = z;
}

/**
 * @brief Converts a string to a t_vec3.
 *
 * @param str The string to be converted.
 * @param vec The t_vec3 to store the converted string.
 *
 * @return t_err Returns OK if the conversion was successful, INVALID_VEC3 if
 * the string is not a valid t_vec3, or ERR_ALLOC if there was an allocation
 * error.
*/
t_err	str_to_vec3(const char *str, t_vec3 *vec)
{
	char	**arr;

	arr = ft_split(str, ',');
	if (arr == NULL)
		return (ERR_ALLOC);
	if (!ft_str_isdouble(arr[0]) || !ft_str_isdouble(arr[1])
		|| !ft_str_isdouble(arr[2]))
	{
		ft_clear_arr((void **) arr, NULL);
		return (INVALID_VEC3);
	}
	vec->x = ft_atod(arr[0]);
	vec->y = ft_atod(arr[1]);
	vec->z = ft_atod(arr[2]);
	ft_clear_arr((void **) arr, NULL);
	return (OK);
}
