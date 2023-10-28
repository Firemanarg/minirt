/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:56:18 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 11:45:03 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_bonus.h"
#include "minirt_bonus.h"

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
