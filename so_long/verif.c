/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:35:54 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/06 16:40:12 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verif(t_data data, char **copy_map, char **copy_map_2)
{
	if (map_size(data.map) == 1 && map_things(&data) == 1
		&& map_error_top_bottom(data.map) == 1 && map_error_sides(data.map) == 1
		&& map_error(data.map) == 1 && verif_path_collectible(copy_map_2) == 1
		&& verif_path_exit(copy_map) == 1)
	{
		ft_free_tab(copy_map);
		ft_free_tab(copy_map_2);
		opening_window(data);
		return ;
	}
	ft_free_tab(data.map);
	ft_free_tab(copy_map);
	ft_free_tab(copy_map_2);
	return ;
}

int	verif_file_name(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0 && str[i] != '.')
		i--;
	if (ft_strncmp(&str[i], ".ber", 5) == 0)
		return (1);
	ft_printf("Error\nFiles name is not good");
	return (0);
}

int	verif_everything(t_data *data)
{
	if (map_things(data) && map_error_sides(data->map))
		return (1);
	else
		ft_printf("Error\nCollectible or map is not good");
	return (0);
}

int	opening_window(t_data data)
{
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "hi");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.move = 0;
	print_elements(&data, data.map);
	print_floor_wall(&data, data.map);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop(data.mlx_ptr);
	return (1);
}
