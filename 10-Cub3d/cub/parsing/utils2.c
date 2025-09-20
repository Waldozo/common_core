/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:19:32 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/09/14 19:19:50 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verif_file_name(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0 && str[i] != '.')
		i--;
	if (ft_strncmp(&str[i], ".cub", 5) == 0)
		return (1);
	printf("Error\nFile name must have .cub extension\n");
	return (0);
}
