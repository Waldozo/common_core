/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:34:21 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/21 19:53:40 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_limits(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_atol(str[i]) > 2147483647 || ft_strlen(str[i]) > 11)
		{
			printf("Error, has to be smaller that INT_MAX\n");
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_isnum(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isnum(str[i]) == 0)
		{
			printf("Error, has to be a positif number\n");
			free(str);
			exit(0);
		}
		i++;
	}
	return (1);
}

int	check_error(char **str)
{
	if (!check_limits(str) || !check_isnum(str))
	{
		exit(0);
	}
	return (1);
}
