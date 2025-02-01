/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:15:33 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/01 14:28:22 by wlarbi-a         ###   ########.fr       */
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
	{
		ft_printf("%s",
			"Error\nThere has to be only one exit and one starting position");
		return (0);
	}
	if (item < 1)
	{
		ft_printf("%s", "Error\nThere has to be at least one item collectible");
		return (0);
	}
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
			else if (map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[4], j * 32, i * 32);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img[0], j * 32, i * 32);
		}
		j = -1;
	}
}
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
		printf("move = %i\n", data->move);
	}
	if (keysym == S && data->map[data->player.x + 1][data->player.y] != '1'
		&& data->map[data->player.x + 1][data->player.y] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0],
			data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1],
			data->player.y * 32, (data->player.x++ + 1) * 32);
		data->move++;
		printf("move = %i\n", data->move);
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
		printf("move = %i\n", data->move);
	}
	if (keysym == A && data->map[data->player.x][data->player.y - 1] != '1'
		&& data->map[data->player.x][data->player.y - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0],
			data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1],
			(data->player.y-- - 1) * 32, data->player.x * 32);
		data->move++;
		printf("move = %i\n", data->move);
	}
}
int	ft_collection(t_data *data)
{
	data->nbr_c = 0;
	if (data->map[data->player.x][data->player.y] == 'C')
	{
		data->nbr_c++;
		data->map[data->player.x][data->player.y] = 0;
	}
	return (data->nbr_c);
}
void	ft_exit(t_data *data, int keysym)
{
	if (map_count(data, 'C') == ft_collection(data))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[5],
			data->pos_flag.x * 32, data->pos_flag.y * 32);
	if (map_count(data, 'C') == ft_collection(data) && keysym == W
		&& data->map[data->player.x - 1][data->player.y] == 'E')
		on_destroy(data);
	if (map_count(data, 'C') == ft_collection(data) && keysym == S
		&& data->map[data->player.x + 1][data->player.y] == 'E')
		on_destroy(data);
	if (map_count(data, 'C') == ft_collection(data) && keysym == D
		&& data->map[data->player.x][data->player.y + 1] == 'E')
		on_destroy(data);
	if (map_count(data, 'C') == ft_collection(data) && keysym == A
		&& data->map[data->player.x][data->player.y - 1] == 'E')
		on_destroy(data);
}
