/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:58:14 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 18:41:05 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_atoi(str[j]) == ft_atoi(str[i]))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

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
			ft_printf("Error\n");
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
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (str[i][0] == '-' && ft_atoi(str[i]) == '0')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if ((str[i][0] == '-' && ft_strlen(str[i]) < 2) || (str[i][0] == '+'
				&& ft_strlen(str[i]) < 2))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	test(char **str)
{
	if (!check_duplicates(str) || !check_limits(str) || !check_isnum(str))
	{
		ft_free_tab(str);
		return (0);
	}
	return (1);
}
