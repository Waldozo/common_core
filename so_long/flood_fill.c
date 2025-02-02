/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:25:54 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/02 19:16:26 by wlarbi-a         ###   ########.fr       */
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

int	verif_path(char **copy_map)
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
			if (copy_map[i][j] == 'E' || copy_map[i][j] == 'C')
			{
				ft_printf("Error path");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
