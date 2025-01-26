/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/26 15:01:25 by wlarbi-a         ###   ########.fr       */
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
	void	*img;
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
	
	
	i = 0;

	if(argc == 2)
	{
		char c;
		c = '\n';
		char **split;
		char *str;
		str = gnl_img(argv[1]);
		split = ft_split((const char *)str, c);
		if((map_size(split)) == 1 && (map_things(split)) == 1 && (map_error_top_bottom(split)) == 1 && (map_error_sides(split)) == 1)
		{
			// printf("%s", str);
			print_table_of_table(split);
		}
		// printf("%s", split[0]);
	}
	
	// printf("error, 2 arguments needed");
	
	// t_data data;
	// // char	*img_wall = "./pics/wall_texture.xpm";
	// // char	*img_floor = "./pics/floor_texture.xpm";
	
	// data.mlx = mlx_init();
	// data.mlx = mlx_init();
	// // if(&gnl_img == 1)
	// // {
	// // 	data.img = mlx_xpm_file_to_image(data.mlx, img_wall , &data.img_width, &data.img_height);
	// // }
	// // else if(&gnl_img == 0)
	// // {
	// // 	data.img = mlx_xpm_file_to_image(data.mlx, img_floor , &data.img_width, &data.img_height);
	// // }
	// mlx_put_image_to_window(data.mlx, data.win_ptr, data.img, 0, 0);
	// data.mlx_ptr = mlx_init();
	// if (!data.mlx_ptr)
	// 	return (1);
	// data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	// if (!data.win_ptr)
	// 	return (free(data.mlx_ptr), 1);
	// // Register key release hook
	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	// mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	// // Register destroy hook
	
	// // Loop over the MLX pointer
	// mlx_loop(data.mlx_ptr);
	// return (0);
}
