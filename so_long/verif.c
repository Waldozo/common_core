/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:35:54 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/01 18:43:24 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif(t_data data, char **copy_map)
{
	if (map_size(data.map) == 1 && map_things(&data) == 1
		&& map_error_top_bottom(data.map) == 1 && map_error_sides(data.map) == 1
		&& map_error(data.map) == verif_path(copy_map))
		return (1);
	return (0);
}