/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:27:42 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/30 18:18:40 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdio.h> 
#include "mlx_int.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "getnextline/get_next_line.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_player
{
	int x;
    int y;
}   t_player;

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
	char	**map;
	t_player	pos_flag;
	int	count;
	int	nbr_c;
	t_player	player;
} t_data;

int	map_error(char **map);
void	coordinates(t_data *data, char **map);
int	map_error_sides(char **map);
int	map_size(char **map);
int	map_error_top_bottom(char **map);
int on_destroy(t_data *data);
char	*gnl_img(char *str);
void    print_table_of_table(char **table);
int	map_things(t_data *data);
void	init_img(t_data *data);
void	print_elements(t_data *data, char **map);
int	map_count(t_data *data, char obj);
int on_destroy(t_data *data);
int on_keypress(int keysym, t_data *data);
void moving(int keysym, t_data *data);
void ft_exit(t_data *data, int keysym);
int	ft_collection(t_data *data);

#define W 119
#define S 115
#define A 97
#define D 100

#endif