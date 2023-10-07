/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:37:49 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/07 18:53:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

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

	if (!is_str_vec3_valid(str))
		return (INVALID_VEC3);
	arr = ft_split(str, ',');
	if (arr == NULL)
		return (ERR_ALLOC);
	vec->x = ft_atod(arr[0]);
	vec->y = ft_atod(arr[1]);
	vec->z = ft_atod(arr[2]);
	ft_clear_strarr(arr);
	return (OK);
}

static int	is_str_vec3_valid(const char *str)
{
	int	i;
	int	comma_count;
	int	last_comma;

	last_comma = -1;
	comma_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			comma_count += 1;
			last_comma = i;
		}
		else if ((str[i] == '-') && (i != last_comma + 1))
			return (0);
		else if ((str[i] != '-') && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (comma_count != 2)
		return (0);
	return (1);
}
