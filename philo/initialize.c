/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:43:48 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/09 18:54:30 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_philosophers(t_philo *philo, int c)
{
	int	i;

	i = 0;
	philo->number_of_philosophers = 0;
	while (i < c)
	{
		philo->number_of_philosophers++;
		i++;
	}
	printf("Number of philosophers: %d\n", philo->number_of_philosophers);
}

void	initialize_time_to_die(t_philo *philo, int c)
{
	int	i;

	i = 0;
	philo->time_to_die = 0;
	while (i < c)
	{
		philo->time_to_die++;
		i++;
	}
	printf("Time to die: %d\n", philo->time_to_die);
}

void	initialize_time_to_eat(t_philo *philo, int c)
{
	int	i;

	i = 0;
	philo->time_to_eat = 0;
	while (i < c)
	{
		philo->time_to_eat++;
		i++;
	}
	printf("Time to eat: %d\n", philo->time_to_eat);
}

void	initialize_time_to_sleep(t_philo *philo, int c)
{
	int	i;

	i = 0;
	philo->time_to_sleep = 0;
	while (i < c)
	{
		philo->time_to_sleep++;
		i++;
	}
	printf("Time to sleep: %d\n", philo->time_to_sleep);
}
