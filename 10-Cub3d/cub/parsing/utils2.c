/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waldozoo <waldozoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:19:32 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/09/15 20:59:48 by waldozoo         ###   ########.fr       */
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
	printf("Error: File name must have .cub extension\n");
	return (0);
}

int	has_line_content(char *line)
{
	int	j;
	int	has_content;

	j = 0;
	has_content = 0;
	while (line[j])
	{
		if (line[j] != ' ' && line[j] != '\t' && line[j] != '\n')
		{
			has_content = 1;
			break ;
		}
		j++;
	}
	return (has_content);
}

int	test_empty_lines_in_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
	{
		printf("Error: Map is NULL\n");
		return (0);
	}
	while (map[i])
	{
		if (!has_line_content(map[i]))
		{
			printf("Error: Empty line found in map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_file_format(char *str)
{
	int	i;
	int	in_map_section;

	if (!str)
		return (0);
	i = 0;
	in_map_section = 0;
	while (str[i])
	{
		if (!in_map_section && (i == 0 || str[i - 1] == '\n'))
		{
			if (is_map_line(str, i))
				in_map_section = 1;
		}
		if (in_map_section && (i == 0 || str[i - 1] == '\n'))
		{
			if (!check_empty_line_in_map(str, i))
				return (0);
		}
		if (!check_texture_after_map(str, i, in_map_section))
			return (0);
		i++;
	}
	return (1);
}
