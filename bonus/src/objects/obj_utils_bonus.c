/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:49:34 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/27 11:46:12 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_bonus.h"

char	*get_obj_name(t_obj_type type)
{
	static char	*names[] = {
		"UNKNOWN", "NONE", "AMBIENT_LIGHT", "CAMERA", "LIGHT", "SPHERE",
		"CYLINDER", "PLANE", "CONE"
	};

	return (names[type + 1]);
}
