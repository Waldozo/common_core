/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:55:09 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/26 15:28:19 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philosopher)
{
	output(philosopher->data, timeoftheday() - philosopher->data->birth,
		philosopher->philo_id, "is thinking");
}

void	sleeping(t_philo *philosopher)
{
	output(philosopher->data, timeoftheday() - philosopher->data->birth,
		philosopher->philo_id, "is sleeping");
	time_to(philosopher->data->time_to_sleep);
}

void	*single_philosopher(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->l_fork);
	output(data, timeoftheday() - data->birth, philo->philo_id,
		"has taken a fork");
	pthread_mutex_unlock(philo->l_fork);
	while (1)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->is_dead)
		{
			pthread_mutex_unlock(&data->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&data->dead_lock);
		usleep(1000);
	}
	return (NULL);
}

void	*philosopher_routine(t_philo *philo, t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->is_dead)
		{
			pthread_mutex_unlock(&data->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&data->dead_lock);
		pthread_mutex_lock(&philo->meal_lock);
		if (data->number_of_meals != -1 && philo->eaten_enough)
		{
			pthread_mutex_unlock(&philo->meal_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_lock);
		eating(philo);
		output(data, timeoftheday() - data->birth, philo->philo_id,
			"is sleeping");
		time_to(data->time_to_sleep);
		output(data, timeoftheday() - data->birth, philo->philo_id,
			"is thinking");
		usleep(1000);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->philo_id % 2)
		usleep(5000);
	if (data->number_of_philosophers == 1)
		return (single_philosopher(philo, data));
	return (philosopher_routine(philo, data));
}
