/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:59:11 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/29 02:27:09 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1
# define ERROR -1
# define BUFFER_SIZE 4096

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	append(char **s1, char *s2, size_t s2_len);
int		split_remaining(char **result, char *remaining);

#endif
