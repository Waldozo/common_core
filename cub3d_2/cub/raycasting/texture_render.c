/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waldozoo <waldozoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:30:00 by waldozoo          #+#    #+#             */
/*   Updated: 2025/09/23 20:30:00 by waldozoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture_pixels(t_game *game)
{
	int	i;

	if (game->texture_pixels)
		free_texture_pixels(game);
	game->texture_pixels = ft_calloc(WINDOW_HEIGHT + 1,
			sizeof(int *));
	if (!game->texture_pixels)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		game->texture_pixels[i] = ft_calloc(WINDOW_WIDTH + 1,
				sizeof(int));
		if (!game->texture_pixels[i])
			return ;
		i++;
	}
}

void	free_texture_pixels(t_game *game)
{
	int	i;

	if (!game->texture_pixels)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT && game->texture_pixels[i])
	{
		free(game->texture_pixels[i]);
		i++;
	}
	free(game->texture_pixels);
	game->texture_pixels = NULL;
}

static int	get_texture_index(t_raycast *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			return (1);  // WEST
		else
			return (0);  // EAST
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (2);  // SOUTH
		else
			return (3);  // NORTH
	}
}

void	update_texture_pixels(t_game *game, t_raycast *ray, int x)
{
	int		y;
	int		color;
	int		tex_index;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	tex_index = get_texture_index(ray);
	tex_x = (int)(game->wall_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		tex_x = TEX_WIDTH - tex_x - 1;
	
	step = 1.0 * TEX_HEIGHT / ray->line_height;
	tex_pos = (ray->draw_start - WINDOW_HEIGHT / 2 + ray->line_height / 2) * step;
	
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = get_texture_color(&game->texture[tex_index], tex_x, tex_y);
		if (tex_index == 3 || tex_index == 0)  // NORTH || EAST
			color = (color >> 1) & 8355711;
		if (color > 0)
			game->texture_pixels[y][x] = color;
		y++;
	}
}