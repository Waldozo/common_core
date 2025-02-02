/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:01 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/02 19:29:17 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*str;
	t_data	data;
	char	**copy_map;

	str = NULL;
	(void)argc;
	str = gnl_img(argv[1]);
	if (!str)
		return (0);
	data.map = ft_split((const char *)str, '\n');
	copy_map = ft_split((const char *)str, '\n');
	free(str);
	coordinates(&data, copy_map);
	if (verif_everything(&data))
		flood_fill(&data, data.player.x, data.player.y, copy_map);
	if (ft_verif(data, copy_map, argv[1]) == 1)
	{
		ft_free_tab(copy_map);
		opening_window(data);
	}
	else
	{
		ft_free_tab(data.map);
		ft_free_tab(copy_map);
	}
}
