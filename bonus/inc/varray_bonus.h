/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varray_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:25:17 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 14:27:20 by gmachado         ###   ########.fr       */
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

// bin_search.c
int			bin_search_gt(t_varray *r, double target,
				int left, int right);
int			first_positive(t_varray *r);

// quicksort.c
void		quicksort(t_varray *r);

// var_array.c
void		free_array(t_varray *r);
t_varray	*new_array(int initial_capacity);
void		reset_array(t_varray *r);
t_err		resize_array(t_varray *r, int new_capacity);

#endif
