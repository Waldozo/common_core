/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:25:54 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/06 11:22:36 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_data *data, int x, int y, char **copy_map)
{
	if (y < 0 || x < 0)
		return (0);
	if (copy_map[x][y] == 'F' || copy_map[x][y] == '1')
		return (0);
	copy_map[x][y] = 'F';
	flood_fill(data, x - 1, y, copy_map);
	flood_fill(data, x + 1, y, copy_map);
	flood_fill(data, x, y - 1, copy_map);
	flood_fill(data, x, y + 1, copy_map);
	return (1);
}

int	flood_fill_collectible(t_data *data, int x, int y, char **copy_map_2)
{
	if (y < 0 || x < 0)
		return (0);
	if (copy_map_2[x][y] == 'F' || copy_map_2[x][y] == '1'
		|| copy_map_2[x][y] == 'E')
		return (0);
	copy_map_2[x][y] = 'F';
	flood_fill_collectible(data, x - 1, y, copy_map_2);
	flood_fill_collectible(data, x + 1, y, copy_map_2);
	flood_fill_collectible(data, x, y - 1, copy_map_2);
	flood_fill_collectible(data, x, y + 1, copy_map_2);
	return (1);
}

int	verif_path_exit(char **copy_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] == 'E')
			{
				ft_printf("Error\nPath doesn't exist");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_path_collectible(char **copy_map_2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (copy_map_2[i])
	{
		j = 0;
		while (copy_map_2[i][j])
		{
			if (copy_map_2[i][j] == 'C')
			{
				ft_printf("Error\nPath doesn't exist");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
