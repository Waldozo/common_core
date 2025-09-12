/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/13 14:02:07 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	name_file(t_data data, char **copy_map, char **copy_map_2)
{
	if (verif_everything(&data))
	{
		flood_fill_collectible(&data, data.player.x, data.player.y, copy_map_2);
		flood_fill(&data, data.player.x, data.player.y, copy_map);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	t_data	data;
	char	**copy_map;
	char	**copy_map_2;

	if (argc != 2)
	{
		ft_printf("Error\nNeed a file name which exits");
		return (0);
	}
	if (!verif_file_name(argv[1]))
		return (1);
	str = gnl_img(argv[1]);
	if (!str || test_map(str) == 0)
		return (0);
	data.map = ft_split((const char *)str, '\n');
	copy_map = ft_split((const char *)str, '\n');
	copy_map_2 = ft_split((const char *)str, '\n');
	free(str);
	coordinates(&data, copy_map);
	name_file(data, copy_map, copy_map_2);
	ft_verif(data, copy_map, copy_map_2);
}
