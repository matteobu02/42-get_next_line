#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
	//printf("%s\n", new);
	return (new);
}

char	*get_next_line(int fd)
{
	int		i;
	int		j;
	int		status;
	char	*line;
	char	 buff;

	if (fd == -1)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	status = 1;
	j = 0;
	while (status)
	{
		i = -1;
		while (++i < BUFFER_SIZE && status)
		{
			status = read(fd, &buff, 1);
			//printf("%d --> %d\n", i + j, status);
			if (status == 0)
				break;
			line = update_line(line, buff, i + j);
			//printf("%d --> %c\n" ,i + j, buff);
			if (buff == '\n')
				return (line);
		}
		j += i;
	}
	if (*line == '\0')
		return (NULL);
	return (line);
}

/*int	main(void)
{
	int fd = open("file",  O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	//str = get_next_line(fd);
	//printf("%s", str);
	//free(str);
	close(fd);
	return (0);
}*/
