/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:34:21 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/19 17:18:04 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_limits(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_atol(str[i]) > 2147483647 || ft_atol(str[i]) < -2147483648
			|| ft_strlen(str[i]) > 11 || (ft_atol(str[i]) == 0
				&& ft_strlen(str[i]) > 1) || (ft_atol(str[i]) == '-'
				&& ft_strlen(str[i]) < 2))
		{
			printf("Error, int max or operator\n");
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
		if (isnum(str[i]) == 0 && str[i][0] != '-' && str[i][0] != '+')
		{
			printf("Error, has to be a number\n");
			return (0);
		}
		if (str[i][0] == '-' && ft_atol(str[i]) == '0')
		{
			printf("Error, only one operator\n");
			return (0);
		}
		if ((str[i][0] == '-' && ft_strlen(str[i]) < 2) || (str[i][0] == '+'
				&& ft_strlen(str[i]) < 2))
		{
			printf("Error, only one operator\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_error(char **str)
{
	if (!check_limits(str) || !check_isnum(str))
	{
		return (0);
	}
	return (1);
}
