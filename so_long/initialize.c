/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/01 15:02:32 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	char	*str;
// 	t_data	data;

// 	str = NULL;
// 	(void)argc;
// 	i = 0;
// 	str = gnl_img(argv[1]);
// 	data.map = ft_split((const char *)str, '\n');
// 	free(str);
// 	if (map_size(data.map) == 1 && map_things(&data) == 1
// 		&& map_error_top_bottom(data.map) == 1 && map_error_sides(data.map) == 1
// 		&& map_error(data.map) == 1)
// 		print_table_of_table(data.map);
// 	// t_player player;
// 	// player.x = 0;
// 	// player.y = 0;
// 	data.move = 0;
// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		return (1);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "hi");
// 	if (!data.win_ptr)
// 		return (free(data.mlx_ptr), 1);
// 	// data.img_height = 32;
// 	// data.img_width = 32;
// 	print_elements(&data, data.map);
// 	coordinates(&data, data.map);
// 	// Register key release hook
// 	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
// 	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
// 		&data);
// 	// Register destroy hook
// 	// Loop over the MLX pointer
// 	mlx_loop(data.mlx_ptr);
// 	return (0);
// }
