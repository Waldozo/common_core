/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/20 11:07:26 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h> 
#include "mlx_int.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "getnextline/get_next_line.h"


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

void	gnl_img(t_data *data, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error, Invalid map");
		exit(EXIT_FAILURE);
	}
	if(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error, map has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	data ->img_width = ()
	// if(line[i] == 1)
	// {
	// 	img = *img_wall;
	// 	mlx_put_image_to_window(mlx, vars.win, img, 0, 0);
	// }
	// else if(line[i] == 0)
	// {
	// 	*img_floor;
	// }
}

int main(void)
{
	t_data data;
	char	*img_wall = "./pics/wall_texture.xpm";
	char	*img_floor = "./pics/floor_texture.xpm";
	
	data.mlx = mlx_init();
	data.mlx = mlx_init();
	if(&gnl_img == 1)
	{
		data.img = mlx_xpm_file_to_image(data.mlx, img_wall , &data.img_width, &data.img_height);
	}
	else if(&gnl_img == 0)
	{
		data.img = mlx_xpm_file_to_image(data.mlx, img_floor , &data.img_width, &data.img_height);
	}
	mlx_put_image_to_window(data.mlx, data.win_ptr, data.img, 0, 0);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	// Register destroy hook
	
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
