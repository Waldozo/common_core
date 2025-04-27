/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:58:00 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/23 20:26:39 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arguments_1(char **argv)
{
	if (ft_atol(argv[1]) <= 0 || ft_atol(argv[1]) > 200)
	{
		printf("Error,the number of philosophers should be between 0 and 200\n");
		return (0);
	}
	if (ft_atol(argv[2]) <= 0)
	{
		printf("Error, the time to die should be bigger than 0\n");
		return (0);
	}
	if (ft_atol(argv[3]) <= 0)
	{
		printf("Error, the time to eat should be bigger than 0\n");
		return (0);
	}
	if (ft_atol(argv[4]) <= 0)
	{
		printf("Error, the time to sleep should be bigger than 0\n");
		return (0);
	}
	return (1);
}

int	check_arguments_2(char **argv)
{
	if (ft_atol(argv[5]) <= 0)
	{
		printf("Error, the number of meals should be bigger than 0\n");
		return (0);
	}
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	if (check_arguments_1(argv) == 0)
		return (0);
	if (argc == 6 && check_arguments_2(argv) == 0)
		return (0);
	return (1);
}
