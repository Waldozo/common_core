/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:46:59 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/26 14:30:26 by wlarbi-a         ###   ########.fr       */
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


int	map_error_top_bottom(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while(map[0][j] != '\0')
	{
		if(map[0][j] != '1')
		{
			printf("%s", "error, map has to be surrounded by walls");
			return(0);
		}
		j++;
	}
	while(map[i])
	{
		if(map[i][0] != '1')
		{
			printf("%s", "error, map has to be surrounded by walls");
			return(0);
		}
		i++;
	}
	return(1);
}
int	mapp_error_sides(char **map)
{
	static	int	i = 0;
	static	int	j = 0;

	while(map[i])
		i++;
	while(map[i-1][j] != '\0')
	{
		if(map[i-1][j] != '1')
		{
			printf("%s", "error, map has to be surrounded by walls");
			return(0);
		}
		j++;
	}
	i = 0;
	while(map[i])
	{
		if(map[i][j-1] != '1')
		{
			printf("%s", "error, map has to be surrounded by walls");
			return(0);
		}
		i++;
	}
	return(1);
}
int	map_size(char **map)
{
	int	i;
	int	j;
	int	size;
	
	size = 0;
	i = 0;
	j = 0;
	while(map[0][size] != '\0')
		size++;
	i = 1;
	while(map[i] != NULL)
	{
		j = 0;
		while(map[i][j] != '\0')
			j++;
		if(j != size)
		{
			printf("%s", "error, map has to be a rectangle");
			return(0);
		}
		i++;		
	}
	return(1);
}
