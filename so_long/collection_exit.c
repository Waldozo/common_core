/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:56:52 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/02 19:15:47 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_exit(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img[0]);
	mlx_destroy_image(data->mlx_ptr, data->img[1]);
	mlx_destroy_image(data->mlx_ptr, data->img[2]);
	mlx_destroy_image(data->mlx_ptr, data->img[3]);
	mlx_destroy_image(data->mlx_ptr, data->img[4]);
	mlx_destroy_image(data->mlx_ptr, data->img[5]);
	ft_free_tab(data->map);
}

void	ft_free_tab(char **tab)
{
	int	i;
	int	size;

	i = 0;
	size = ft_size_tab(tab);
	while (i < size)
		free(tab[i++]);
	free(tab);
}

int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
		return (i + 1);
	}
	return (0);
}
