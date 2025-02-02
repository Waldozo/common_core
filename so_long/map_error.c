/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:46:59 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/02 19:17:49 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error_top_bottom(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
		{
			ft_printf("%s", "Error, map has to be surrounded by walls");
			return (0);
		}
		j++;
	}
	while (map[i] != NULL)
	{
		if (map[i][0] != '1')
		{
			ft_printf("%s", "Error, map has to be surrounded by walls");
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_error(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != 'E'
				&& map[i][j] != 'C' && map[i][j] != '0')
			{
				ft_printf("%s", "Error, map has to include only an exit,\
					a character, at least a coin, floors and walls");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	map_error_sides(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
		i++;
	while (map[i - 1][j] != '\0')
	{
		if (map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_size(char **map)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	i = 0;
	j = 0;
	while (map[0][size] != '\0')
		size++;
	i = 1;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		if (j != size)
		{
			ft_printf("%s", "Error, map has to be a rectangle");
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_count(t_data *data, char obj)
{
	int	i;
	int	j;

	data->count = 0;
	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == obj)
			{
				data->count++;
			}
			if (data->map[i][j] == 'E')
			{
				data->pos_flag.x = j;
				data->pos_flag.y = i;
			}
			j++;
		}
		i++;
	}
	return (data->count);
}
