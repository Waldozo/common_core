/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:16:58 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/20 09:19:49 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl_img(char *str)
{
	char	*map_line;
	char	*map;
	char	*tmp;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_line = get_next_line(fd);
	if (!map_line)
		exit(0);
	map = ft_strdup("");
	while (map_line)
	{
		tmp = map;
		map = ft_strjoin((const char *)map, (const char *)map_line);
		free(tmp);
		free(map_line);
		map_line = get_next_line(fd);
	}
	close(fd);
	free(map_line);
	return (map);
}

int	test_map(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[0] == '\n')
		{
			free(map);
			ft_printf("Error,\nnew line in file\n");
			return (0);
		}
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_printf("Error,\nnew line in file\n");
			return (0);
		}
		i++;
	}
	return (1);
}
/*void	print_table_of_table(char **table)
{
	int i;

	i = 0;
	while (table[i])
		ft_putendl_fd(table[i++], 1);
}*/
