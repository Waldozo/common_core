/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:15:33 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/30 14:42:59 by wlarbi-a         ###   ########.fr       */
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
	
	if(start != 1 || exit != 1)
	{
		ft_printf("%s", "Error\nThere has to be only one exit and one starting position");
		return(0);
	}
	if(item < 1)
	{
		ft_printf("%s", "Error\nThere has to be at least one item collectible");
		return(0);
	}
	return(1);
}

void	init_img(t_data *data)
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
	
	data->img[0] =  "./pics/floor_texture.xpm";
	data->img[1] = "./pics/perso_tetxure.xpm";
	data->img[2] =  "./pics/coin_texture.xpm";
	data->img[3] =   "./pics/exit_texture.xpm";
	data->img[4] =  "./pics/wall_texture.xpm";
}
void	print_elements(t_data *data, char **map)
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
	data->img[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./pics/floor_texture.xpm", &data->img_width, &data->img_height);
	data->img[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./pics/perso_texture.xpm", &data->img_width, &data->img_height);
	data->img[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./pics/coin_texture.xpm", &data->img_width, &data->img_height);
	data->img[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./pics/exit_texture.xpm", &data->img_width, &data->img_height);
	data->img[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./pics/wall_texture.xpm", &data->img_width, &data->img_height);
	
	while(map[++i])
	{
		while (map[i][++j])
		{
			if(map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], j * 32, i * 32);
			else if(map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[2], j * 32, i * 32);	
			else if(map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[3], j * 32, i * 32);
			else if(map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[4], j * 32, i * 32);
			else if(map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0], j * 32, i * 32);
		}
		j = -1;
	}	
}
void moving(int keysym, t_data *data)
{
	if (keysym == W && data->map[data->player.x-1][data->player.y] != '1' && data->map[data->player.x-1][data->player.y] != 'E')
    {
    	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0], data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], data->player.y * 32, (data->player.x-- - 1) * 32);
    }
	if(keysym == S && data->map[data->player.x+1][data->player.y] != '1' && data->map[data->player.x+1][data->player.y] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0], data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], data->player.y * 32, (data->player.x++ + 1) * 32);
	
	}
	if(keysym == D && data->map[data->player.x][data->player.y + 1] != '1' && data->map[data->player.x][data->player.y + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0], data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], (data->player.y++ + 1)* 32, data->player.x * 32);
	}
	if(keysym == A && data->map[data->player.x][data->player.y - 1] != '1'  && data->map[data->player.x][data->player.y - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0], data->player.y * 32, data->player.x * 32);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], (data->player.y-- - 1)* 32, data->player.x * 32);
	}
}
int	ft_collection(t_data *data)
{
	data->nbr_c = 0;
	if(data->map[data->player.x][data->player.y] == 'C')
	{
		data->nbr_c++;
		data->map[data->player.x][data->player.y] = 0;
	}
	return(data->nbr_c);
}
void ft_exit(t_data *data, int keysym)
{
	if(map_count(data, 'C') == ft_collection(data) && keysym == W && data->map[data->player.x-1][data->player.y] == 'E' )
		on_destroy(data);
	if(map_count(data, 'C') == ft_collection(data) && keysym == S && data->map[data->player.x+1][data->player.y] == 'E' )
		on_destroy(data);
	if(map_count(data, 'C') == ft_collection(data) && keysym == D && data->map[data->player.x][data->player.y+1] == 'E' )
		on_destroy(data);
	if(map_count(data, 'C') == ft_collection(data) && keysym == A && data->map[data->player.x][data->player.y-1] == 'E' )
		on_destroy(data);
}

