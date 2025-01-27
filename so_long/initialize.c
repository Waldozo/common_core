/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/27 11:11:00 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h> 
#include "mlx_int.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "getnextline/get_next_line.h"
#include "libft/libft.h"

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void	*mlx;
	void	*img[256];
	char	*img_wall;
	char	*img_floor;
	char	*img_perso;
	char	*img_coin;
	char	*img_exit;
	int		img_width;
	int		img_height;
} t_data;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	if (keysym == DestroyNotify)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	// printf("Pressed key: %d\\n", keysym);
	return (0);
}

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

int	map_error_top_bottom(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while(map[0][j] != '\0')
	{
		if(map[0][j] != '1')
		{
			printf("%s", "error, map has to be surrounded by walls");
			return(0);
		}
		j++;
	}
	while(map[i])
	{
		if(map[i][0] != '1')
		{
			printf("%s", "error, map has to be surrounded by walls");
			return(0);
		}
		i++;
	}
	return(1);
}
int	map_error_sides(char **map)
{
	static	int	i = 0;
	static	int	j = 0;

	while(map[i])
		i++;
	while(map[i-1][j] != '\0')
	{
		if(map[i-1][j] != '1')
		{
			printf("%s", "error, map has to be surrounded by walls");
			return(0);
		}
		j++;
	}
	i = 0;
	while(map[i])
	{
		if(map[i][j-1] != '1')
		{
			printf("%s", "error, map has to be surrounded by walls");
			return(0);
		}
		i++;
	}
	return(1);
}
int	map_size(char **map)
{
	int	i;
	int	j;
	int	size;
	
	size = 0;
	i = 0;
	j = 0;
	while(map[0][size] != '\0')
		size++;
	i = 1;
	while(map[i] != NULL)
	{
		j = 0;
		while(map[i][j] != '\0')
			j++;
		if(j != size)
		{
			printf("%s", "error, map has to be a rectangle");
			return(0);
		}
		i++;		
	}
	return(1);
}
int	map_count(char **map, char obj)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while(map[i] != NULL)
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if(map[i][j] == obj)
				count++;
			j++;
		}
		i++;		
	}
	return(count);
}
int	map_things(char **map)
{
	int	exit;
	int	item;
	int	start;

	start = map_count(map, 'P');
	item = map_count(map, 'C');
	exit = map_count(map, 'E');
	
	if(start != 1 || exit != 1)
	{
		printf("%s", "Error\nThere has to be only one exit and one starting position");
		return(0);
	}
	if(item < 1)
	{
		printf("%s", "Error\nThere has to be at least one item collectible");
		return(0);
	}
	return(1);
}

void	init_img(t_data data)
{
	int	i;
	char *img_wall;
	char	*img_floor;
	char	*img_perso;
	char	*img_coin;
	char	*img_exit;
	
	i = 0;
	img_floor = "./pics/floor_texture.xpm";
	img_perso = "./pics/perso_tetxure.xpm";
	img_coin =  "./pics/coin_texture.xpm";
	img_exit = "./pics/exit_texture.xpm";
	img_wall = "./pics/wall_texture.xpm";
	
	data.img[0] =  "./pics/floor_texture.xpm";
	data.img[1] = "./pics/perso_tetxure.xpm";
	data.img[2] =  "./pics/coin_texture.xpm";
	data.img[3] =   "./pics/exit_texture.xpm";
	data.img[4] =  "./pics/wall_texture.xpm";
}
void	print_elements(t_data data, char **map)
{
	int	i;
	int	j;
	char *img_wall;
	char	*img_floor;
	char	*img_perso;
	char	*img_coin;
	char	*img_exit;
	
	img_floor = "./pics/floor_texture.xpm";
	img_perso = "./pics/perso_tetxure.xpm";
	img_coin =  "./pics/coin_texture.xpm";
	img_exit = "./pics/exit_texture.xpm";
	img_wall = "./pics/wall_texture.xpm";
	i = -1;
	j = -1;
	data.img[0] = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/floor_texture.xpm", &data.img_width, &data.img_height);
	data.img[1] = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/perso_texture.xpm", &data.img_width, &data.img_height);
	data.img[2] = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/coin_texture.xpm", &data.img_width, &data.img_height);
	data.img[3] = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/exit_texture.xpm", &data.img_width, &data.img_height);
	data.img[4] = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/wall_texture.xpm", &data.img_width, &data.img_height);
	
	while(map[++i])
	{
		while (map[i][++j])
		{
			if(map[i][j] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[1], j * 32, i * 32);
			else if(map[i][j] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[2], j * 32, i * 32);	
			else if(map[i][j] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[3], j * 32, i * 32);
			else if(map[i][j] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[4], j * 32, i * 32);
			else if(map[i][j] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[0], j * 32, i * 32);
		}
		j = -1;
	}
	
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
	char **split = NULL;
	char *str = NULL;
	
	(void)argc;
	i = 0;
	str = gnl_img(argv[1]);
	split = ft_split((const char *)str, '\n');
	if((map_size(split)) == 1 && (map_things(split)) == 1 && (map_error_top_bottom(split)) == 1 && (map_error_sides(split)) == 1)
		print_table_of_table(split);
	
	// printf("error, 2 arguments needed");
	
	t_data data;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "hi");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.img_height = 32;
	data.img_width = 32;
	print_elements(data, split);
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	// Register destroy hook
	
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
