/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:20:15 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/09/20 15:47:25 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Cette fonction calcule la distance jusqu'au mur pour un seul rayon
** Paramètres:
** - ray: Structure contenant les informations du rayon (direction, position...)
** - map: La carte du niveau
** Retourne: La distance jusqu'au mur et les informations de collision
*/

void	calculate_ray(t_ray *ray, t_map *map)
{
	if (ray->map_x < 0 || ray->map_x >= map->width || ray->map_y < 0
		|| ray->map_y >= map->height)
		return ;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

/*
** Algorithme DDA (Digital Differential Analysis) pour trouver l'intersection
** avec un mur. Cette fonction continue le calcul commencé dans calculate_ray.
*/
void	perform_dda(t_ray *ray, t_map *map)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x >= 0 && ray->map_x < map->width && ray->map_y >= 0
			&& ray->map_y < map->height
			&& map->data[ray->map_y][ray->map_x] == '1')
			break ;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
}

/*
** Cette fonction initialise les variables nécessaires pour le raycasting
** pour un seul rayon. Elle est appelée pour chaque colonne de l'écran.
*/
void	init_ray(t_ray *ray, t_player *player, double camera_x)
{
	ray->pos_x = player->x;
	ray->pos_y = player->y;
	ray->dir_x = player->dir_x + player->plane_x * camera_x;
	ray->dir_y = player->dir_y + player->plane_y * camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}
