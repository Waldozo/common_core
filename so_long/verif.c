/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:35:54 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/01 19:52:23 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif(t_data data, char **copy_map, char *str)
{
	if (map_size(data.map) == 1 && map_things(&data) == 1
		&& map_error_top_bottom(data.map) == 1 && map_error_sides(data.map) == 1
		&& map_error(data.map) == 1 && verif_path(copy_map) == 1 && verif_file_name(str) == 1)
		return (1);
    
	return (0);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
    //printf("%s", s1);
    while (s1[i])
		i++;
	while (s1[i] != '.')
		i--;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
int	verif_file_name(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
		i--;
	if (ft_strcmp(&str[i], ".ber") == 0)
		return (1);
    else
    {
        ft_printf("le nom du fichier n'est pas bon");
	    return(0);
    }
    return(0);
}
