/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:23:10 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/02 19:18:02 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moving_up_down(int keysym, t_data *data)
{
	if (keysym == W && data->map[data->player.x - 1][data->player.y] != '1'
		&& data->map[data->player.x - 1][data->player.y] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0],
			data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1],
			data->player.y * 32, (data->player.x-- - 1) * 32);
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	if (keysym == S && data->map[data->player.x + 1][data->player.y] != '1'
		&& data->map[data->player.x + 1][data->player.y] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0],
			data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1],
			data->player.y * 32, (data->player.x++ + 1) * 32);
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
}

void	moving_sides(int keysym, t_data *data)
{
	if (keysym == D && data->map[data->player.x][data->player.y + 1] != '1'
		&& data->map[data->player.x][data->player.y + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0],
			data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1],
			(data->player.y++ + 1) * 32, data->player.x * 32);
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	if (keysym == A && data->map[data->player.x][data->player.y - 1] != '1'
		&& data->map[data->player.x][data->player.y - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0],
			data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1],
			(data->player.y-- - 1) * 32, data->player.x * 32);
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
}
