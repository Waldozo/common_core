/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waldozoo <waldozoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:45:18 by waldozoo          #+#    #+#             */
/*   Updated: 2025/09/15 21:08:40 by waldozoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_all_lines(int fd)
{
	char	*map_line;
	char	*map;
	char	*tmp;

	map_line = get_next_line(fd);
	if (!map_line)
		return (NULL);
	map = ft_strdup("");
	if (!map)
		return (free(map_line), NULL);
	while (map_line)
	{
		tmp = map;
		map = ft_strjoin((const char *)map, (const char *)map_line);
		free(tmp);
		free(map_line);
		map_line = get_next_line(fd);
	}
	free(map_line);
	return (map);
}

char	*gnl_img(char *str)
{
	char	*map;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("Erreur: impossible d'ouvrir le fichier\n");
		return (NULL);
	}
	map = read_all_lines(fd);
	close(fd);
	if (!map)
	{
		printf("Erreur: fichier vide ou illisible\n");
		return (NULL);
	}
	if (!validate_file_format(map))
	{
		free(map);
		return (NULL);
	}
	return (map);
}

int	is_map_line(char *str, int start)
{
	int	j;
	int	found_map_char;

	j = start;
	found_map_char = 0;
	while (str[j] && str[j] == ' ')
		j++;
	while (str[j] && str[j] != '\n')
	{
		if (str[j] == '1' || str[j] == '0')
			found_map_char = 1;
		else if (str[j] != ' ' && str[j] != '1' && str[j] != '0')
			return (0);
		j++;
	}
	return (found_map_char && (j - start) > 5);
}

int	is_empty_line_in_map(char *str, int pos)
{
	int	i;
	int	line_start;

	line_start = pos;
	while (line_start > 0 && str[line_start - 1] != '\n')
		line_start--;
	i = line_start;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (i > line_start || (str[i] == '\n' && line_start == pos));
}

int	is_texture_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F'
		|| c == 'C');
}
