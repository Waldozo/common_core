/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:22:07 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/02 19:17:29 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	free_exit(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	coordinates(t_data *data, char **map)
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
			if (map[i][j] == 'P')
			{
				data->player.x = i;
				data->player.y = j;
			}
			j++;
		}
		i++;
	}
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		on_destroy(data);
		exit(0);
	}
	if (keysym == DestroyNotify)
	{
		on_destroy(data);
		exit(0);
	}
	moving_up_down(keysym, data);
	moving_sides(keysym, data);
	ft_collection(data);
	ft_exit(data, keysym);
	return (0);
}
