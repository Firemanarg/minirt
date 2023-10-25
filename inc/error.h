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

# include "libft_x.h"

typedef enum e_err
{
	OK = 0,
	ERR_ALLOC,
	INVALID_VEC3,
	INVALID_ARG,
	INVALID_TYPE,
	INVALID_ARG_COUNT,
	INVALID_RATIO,
	INVALID_COLOR,
	ERR_PARSING_FILE,
	ERR_WRONG_USAGE,
	TOO_MANY_AMBIENT_LIGHTS,
	TOO_MANY_CAMERAS,
	TOO_MANY_LIGHTS,
	MISSING_AMBIENT_LIGHT,
	MISSING_CAMERA,
	MISSING_LIGHT,
}	t_err;

void	print_error(char *context, t_err err, int line);

#endif
