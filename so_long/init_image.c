/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:15:33 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/25 19:22:40 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_things(t_data *data)
{
	int	exit;
	int	item;
	int	start;

	start = map_count(data, 'P');
	item = map_count(data, 'C');
	exit = map_count(data, 'E');
	if (start != 1 || exit != 1)
		return (0);
	if (item < 1)
		return (0);
	return (1);
}

void	init_img(t_data *data)
{
	data->img[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./pics/floor_texture.xpm", &data->img_width, &data->img_height);
	data->img[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./pics/perso_texture.xpm", &data->img_width, &data->img_height);
	data->img[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./pics/coin_texture.xpm", &data->img_width, &data->img_height);
	data->img[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./pics/exit_texture_blocked.xpm", &data->img_width,
			&data->img_height);
	data->img[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./pics/wall_texture.xpm", &data->img_width, &data->img_height);
	data->img[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./pics/exit_texture.xpm", &data->img_width, &data->img_height);
}

void	print_elements(t_data *data, char **map)
{
	int	i;
	int	j;

	init_img(data);
	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[1], j * 32, i * 32);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[2], j * 32, i * 32);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[3], j * 32, i * 32);
		}
		j = -1;
	}
}

void	print_floor_wall(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[4], j * 32, i * 32);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[0], j * 32, i * 32);
		}
		j = -1;
	}
}
