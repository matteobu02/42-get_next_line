/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:38:53 by mbucci            #+#    #+#             */
/*   Updated: 2021/09/22 01:14:32 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
		i++;
	return (i);
}

int	check_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

char	*ft_strcpy(char *dst, char *src)
{
	if (!dst || !src)
		return (NULL);
	while (*src)
		*dst++ = *src++;
	return (dst);
}

char	*update_line(char *line, char c)
{
	char	*n_line;

	n_line = (char *)malloc(ft_strlen(line) + 1);
	if (!n_line)
		return (NULL);
	ft_strcpy(n_line, line);
	n_line[ft_strlen(line) + 1] = c;
	free(line);
	return (n_line);
}

char	*get_next_line(int fd)
{
	int		i;
	char	buff;
	char	*line;

	line = (char *)malloc(BUFF_SIZE + 1);
	while (check_line(line) == 0)
	{
		i = -1;
		printf("%d\n", i);
		while (++i < BUFF_SIZE)
		{
			read(fd, &buff, BUFF_SIZE);
			line = update_line(line, buff);
			if (!line)
				return (NULL);
		}
		if (i < BUFF_SIZE)
			return (line);
	}
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	int fd = open("file", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s.\n", str);
	//free(str);
	close(fd);
	return (0);
}
