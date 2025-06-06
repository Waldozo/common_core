/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:27:42 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/27 15:57:49 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "getnextline/get_next_line.h"
# include "libft/libft.h"
# include "mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx;
	void		*img[256];
	int			img_width;
	int			img_height;
	int			move;
	char		**map;
	t_player	pos_flag;
	int			count;
	int			nbr_c;
	t_player	player;
}				t_data;

int				map_error(char **map);
void			coordinates(t_data *data, char **map);
int				map_error_sides(char **map);
int				map_size(char **map);
int				map_error_top_bottom(char **map);
int				on_destroy(t_data *data);
char			*gnl_img(char *str);
int				map_things(t_data *data);
void			print_elements(t_data *data, char **map);
int				map_count(t_data *data, char obj);
int				on_destroy(t_data *data);
int				on_keypress(int keysym, t_data *data);
void			moving_up_down(int keysym, t_data *data);
void			moving_sides(int keysym, t_data *data);
void			ft_exit(t_data *data, int keysym);
void			ft_collection(t_data *data);
void			init_img(t_data *data);
int				flood_fill(t_data *data, int x, int y, char **copy_map);
int				flood_fill_collectible(t_data *data, int x, int y,
					char **copy_map_2);
int				verif_path_collectible(char **copy_map_2);
int				verif_path_exit(char **copy_map);
void			ft_verif(t_data data, char **copy_map, char **copy_map_2);
int				verif_file_name(char *str);
int				opening_window(t_data data);
int				verif_everything(t_data *data);
void			print_floor_wall(t_data *data, char **map);
void			free_exit(t_data *data);
void			ft_free_tab(char **tab);
int				ft_size_tab(char **tab);
void			ft_count_exit(t_data *data);
void			print_table_of_table(char **table);
int				test_map(char *map);

# define W 119
# define S 115
# define A 97
# define D 100

#endif