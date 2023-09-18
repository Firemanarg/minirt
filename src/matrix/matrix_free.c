/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:56:18 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 01:59:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <matrix.h>

void	matrix_free(t_matrix *m)
{
	int	i;

	i = 0;
	while (i < m->rows)
	{
		free(m->data[i]);
		i += 1;
	}
	free(m->data);
	free(m);
}
