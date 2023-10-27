/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:47:26 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 13:47:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include "libft_x.h"

# define TXT_COLOR_RED "\033[0;31m"
# define TXT_COLOR_GREEN "\033[0;32m"
# define TXT_COLOR_YELLOW "\033[0;33m"
# define TXT_COLOR_BLUE "\033[0;34m"
# define TXT_COLOR_MAGENTA "\033[0;35m"
# define TXT_COLOR_CYAN "\033[0;36m"
# define TXT_COLOR_RESET "\033[0m"

# define TERM_HIDE_CURSOR "\033[?25l"
# define TERM_SHOW_CURSOR "\033[?25h"

# define PROGRESS_BAR_SIZE 12

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
	INVALID_DIAMETER,
	INVALID_FOV,
	INVALID_HEIGHT,
	INVALID_DIRECTION,
	ERR_RENDERING
}	t_err;

// error.c
int		baracapy(void);
void	minirt_title(void);
void	print_error(char *context, t_err err, int line);
void	print_msg(char *context, char *msg, char *color);

// progress_bar.c
void	print_progress(int progress, int total, char *context);

#endif
