/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:56:18 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 12:27:19 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "minirt.h"

void	matrix_free(t_matrix *m)
{
	int	i;

	if (m == NULL)
		return ;
	i = 0;
	while (i < m->rows)
	{
		free(m->data[i]);
		i += 1;
	}
	free(m->data);
	free(m);
}
