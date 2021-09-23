/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:06:35 by mbucci            #+#    #+#             */
/*   Updated: 2021/09/23 23:19:34 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;

	if (fd == -1)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line = make_line(line, fd);
	if (*line == '\0')
		return (NULL);
	return (line);
}
