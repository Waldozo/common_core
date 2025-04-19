/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:47:09 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/19 19:50:52 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *monitor(void *arg)
{
	t_data *data = (t_data *)arg;
	int i;

	while (1)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->philosopher[i].meal_lock);
			long long time_since_last_meal = timeoftheday() - data->philosopher[i].last_meal;
			pthread_mutex_unlock(&data->philosopher[i].meal_lock);
			
			if (time_since_last_meal > data->time_to_die)
			{
				pthread_mutex_lock(&data->dead_lock);
				if (!data->is_dead)
				{
					data->is_dead = 1;
					pthread_mutex_unlock(&data->dead_lock);
					output(data, timeoftheday() - data->birth,
						data->philosopher[i].philo_id, "died");
					return NULL;
				}
				pthread_mutex_unlock(&data->dead_lock);
			}
			i++;
			usleep(100);
		}
	}
	return NULL;
}

void	eating(t_philo *philosopher)
{
	if (philosopher->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philosopher->l_fork);
		output(philosopher->data, timeoftheday() - philosopher->data->birth,
			philosopher->philo_id, "has taken a fork");
		pthread_mutex_lock(philosopher->r_fork);
		output(philosopher->data, timeoftheday() - philosopher->data->birth,
			philosopher->philo_id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philosopher->r_fork);
		output(philosopher->data, timeoftheday() - philosopher->data->birth,
			philosopher->philo_id, "has taken a fork");
		pthread_mutex_lock(philosopher->l_fork);
		output(philosopher->data, timeoftheday() - philosopher->data->birth,
			philosopher->philo_id, "has taken a fork");
	}
	pthread_mutex_lock(&philosopher->meal_lock);
	philosopher->last_meal = timeoftheday();
	pthread_mutex_unlock(&philosopher->meal_lock);
	output(philosopher->data, timeoftheday() - philosopher->data->birth,
		philosopher->philo_id, "is eating");
	time_to(philosopher->data->time_to_eat);
	pthread_mutex_unlock(philosopher->r_fork);
	pthread_mutex_unlock(philosopher->l_fork);
}


void	thinking(t_philo *philosopher)
{
	output(philosopher->data, timeoftheday() - philosopher->data->birth, philosopher->philo_id, "is thinking");
}

void	sleeping(t_philo *philosopher)
{
	output(philosopher->data, timeoftheday() - philosopher->data->birth, philosopher->philo_id, "is sleeping");
	time_to(philosopher->data->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int ate;
	ate = 0;

	philo = (t_philo *)arg;
	data = philo->data;
	
	while (1)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->is_dead)
		{
			pthread_mutex_unlock(&data->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&data->dead_lock);
		
		thinking(philo);
		eating(philo);
		ate++;
		if(ate == philo->data->number_of_meals)
		{
			break ;
		}
		sleeping(philo);
	}
	return (NULL);
}
