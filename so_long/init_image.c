/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:15:33 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/27 11:16:10 by wlarbi-a         ###   ########.fr       */
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