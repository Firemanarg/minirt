/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varray_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:25:17 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:37:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARRAY_BONUS_H
# define VARRAY_BONUS_H

# include "error_bonus.h"

typedef struct s_varray
{
	int		capacity;
	int		length;
	void	*arr;
}	t_varray;

// var_array.c
t_varray	*new_array(int initial_capacity);
t_err		resize_array(t_varray *r, int new_capacity);
void		free_array(t_varray *r);
void		reset_array(t_varray *r);

// quicksort.c
void		quicksort(t_varray *r);

// bin_search.c
int			bin_search_gt(t_varray *r, double target,
				int left, int right);
int			first_positive(t_varray *r);

#endif
