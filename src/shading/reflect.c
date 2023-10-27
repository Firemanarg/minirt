/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:34:22 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/06 12:22:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void	reflect(t_vec3 *incident, t_vec3 *normal, t_vec3 *reflected)
{
	t_vec3	tmp;

	multiply(normal, 2.0 * dot(incident, normal), &tmp);
	subtract(incident, &tmp, reflected);
}
