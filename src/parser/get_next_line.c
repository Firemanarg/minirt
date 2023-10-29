/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:02:55 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/05 13:25:40 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	remaining[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*result;
	int			should_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	should_read = split_remaining(&result, remaining);
	while (should_read == TRUE)
	{
		bytes_read = read(fd, remaining, BUFFER_SIZE);
		if (!bytes_read && *result)
			return (result);
		if (bytes_read <= 0)
		{
			free(result);
			return (NULL);
		}
		remaining[bytes_read] = '\0';
		should_read = split_remaining(&result, remaining);
	}
	return (result);
}
