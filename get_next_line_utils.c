/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:38:59 by mbucci            #+#    #+#             */
/*   Updated: 2021/09/23 23:25:16 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
}

char	*update_line(char *line, char c, int len)
{
	char	*new;

	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, line);
	free(line);
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}

char	*make_line(char *line, int fd)
{
	int		i;
	int		j;
	int		status;
	char	buff;

	status = 1;
	j = 0;
	while (status)
	{
		i = -1;
		while (++i < BUFFER_SIZE && status)
		{
			status = read(fd, &buff, 1);
			if (status == 0)
				break ;
			line = update_line(line, buff, i + j);
			if (buff == '\n')
				return (line);
		}
		j += i;
	}
	return (line);
}
