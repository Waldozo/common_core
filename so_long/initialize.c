/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/16 11:21:33 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h> 
#include "mlx_int.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_vars;


int	main(void)
{
	void	*mlx;
	t_img	*img;
	char	*relative_path = "./floor_texture.xpm";
	int		img_width;
	int		img_height;
	t_vars	vars;

	mlx = mlx_init();
	vars.mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_put_image_to_window(mlx, vars.win, img, 0, 0);
	mlx_put_image_to_window(mlx, vars.win, img, img_width *1, 0);
	mlx_put_image_to_window(mlx, vars.win, img, img_width *2, 0);
	mlx_loop(vars.mlx);
}

// int	close(int keycode, t_vars *vars)
// {
// 	if(keycode == 17)
// 	{
// 		mlx_destroy_image(t_xvar *xvar, t_img *img);
// 		mlx_destroy_window(t_xvar *xvar,t_win_list *win)
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, close, &vars);
// 	mlx_loop(vars.mlx);
// }
