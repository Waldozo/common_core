/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/30 14:42:27 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl_img(char *str)
{
	char	*map_line;
	char	*map;
	char	*tmp;
	int	fd;
	
	fd = open(str ,O_RDONLY);
	if(fd < 0)
		return(NULL);
	map_line = get_next_line(fd);
	map = ft_strdup("");
	while(map_line)
	{
		// if(!map_line || map_line[0] != 1)
		// 	return(NULL);
		tmp = map;
		map = ft_strjoin((const char *)map, (const char *)map_line);
		free(tmp);
		free(map_line);
		map_line = get_next_line(fd);
	}
	return(map);
}

void    print_table_of_table(char **table)
{
    int    i;

    i = 0;
    while (table[i])
        ft_putendl_fd(table[i++], 1);
}

int main(int argc, char **argv)
{
	int	i;
	char *str = NULL;
	t_data data;
	(void)argc;
	i = 0;
	str = gnl_img(argv[1]);
	data.map = ft_split((const char *)str, '\n'); 
	if((map_size(data.map)) == 1 && (map_things(&data)) == 1 && (map_error_top_bottom(data.map)) == 1 && (map_error_sides(data.map)) == 1)
		print_table_of_table(data.map);
	t_player player;
	
	player.x = 0;
	player.y = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "hi");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.img_height = 32;
	data.img_width = 32;
	print_elements(&data, data.map);
	coordinates(&data, data.map);
	// Register key release hook
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	// Register destroy hook
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
