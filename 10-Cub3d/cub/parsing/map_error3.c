/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:46:59 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/09/14 18:51:28 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(t_data *data, int x, int y, char **copy_map)
{
	if (y < 0 || x < 0)
		return (0);
	if (copy_map[x][y] == 'F' || copy_map[x][y] == '1' || copy_map[x][y] == ' ')
		return (0);
	copy_map[x][y] = 'F';
	flood_fill(data, x - 1, y, copy_map);
	flood_fill(data, x + 1, y, copy_map);
	flood_fill(data, x, y - 1, copy_map);
	flood_fill(data, x, y + 1, copy_map);
	return (1);
}

int	verif_path(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (++i, map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
			{
				if ((i > 0 && map[i - 1][j] == ' ') ||
					(map[i + 1] && map[i + 1][j] == ' ') ||
					(j > 0 && map[i][j - 1] == ' ') ||
					(j < (int)ft_strlen(map[i]) - 1 && map[i][j + 1] == ' '))
				{
					printf("error space near floor\n");
					return (0);
				}
			}
			j++;
		}
	}
	return (1);
}

int	is_valid_texture_prefix(char first_char, char next_char)
{
	if ((first_char == 'N' && next_char == 'O') || (first_char == 'S'
			&& next_char == 'O') || (first_char == 'W' && next_char == 'E')
		|| (first_char == 'E' && next_char == 'A') || (first_char == 'F'
			&& next_char == ' ') || (first_char == 'C' && next_char == ' ')
		|| first_char == '\0')
		return (1);
	return (0);
}

int	file_things(t_data *data)
{
	int		i;
	char	first_char;
	int		index;
	char	next_char;

	i = 0;
	while (data->file2[i] != NULL)
	{
		if (data->file2[i])
		{
			index = get_first_non_space_index(data->file2[i]);
			first_char = data->file2[i][index];
			next_char = data->file2[i][index + 1];
			if (!is_valid_texture_prefix(first_char, next_char))
			{
				printf("error, file2 not good\n");
				return (0);
			}
			if (!validate_texture_line(data->file2[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
