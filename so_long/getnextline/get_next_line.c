/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:31:48 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/25 14:17:40 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		byte;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[byte] = 0;
		str = ftr_strjoin(str, buffer);
		free(buffer);
		if (ftr_strchr(str, '\n'))
			break ;
	}
	return (str);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	// free(buffer);
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc((ftr_strlen(buffer) - i + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
#include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("get.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	i = 1;
// 	while (i)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 		{
// 			i = 0;
// 			free(line);
// 			break ;
// 		}
// 		printf("Line: %s", line);
// 		free(line);
// 	}
// 	return (0);
// }

