/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:47:26 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/16 21:06:12 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_err
{
	OK = 0,
	ERR_ALLOC,
	INVALID_VEC3,
	INVALID_ARG,
	INVALID_TYPE
}	t_err;

#endif
