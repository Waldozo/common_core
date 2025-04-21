/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:53:37 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/21 15:15:14 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_order(t_philo *philosopher, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	if (philosopher->philo_id < (philosopher->philo_id + 1)
		% philosopher->data->number_of_philosophers)
	{
		*first_fork = philosopher->l_fork;
		*second_fork = philosopher->r_fork;
	}
	else
	{
		*first_fork = philosopher->r_fork;
		*second_fork = philosopher->l_fork;
	}
}

void	take_forks(t_philo *philosopher, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(first_fork);
	output(philosopher->data, timeoftheday() - philosopher->data->birth,
		philosopher->philo_id, "has taken a fork");
	pthread_mutex_lock(second_fork);
	output(philosopher->data, timeoftheday() - philosopher->data->birth,
		philosopher->philo_id, "has taken a fork");
}

void	start_eating(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->meal_lock);
	philosopher->last_meal = timeoftheday();
	output(philosopher->data, timeoftheday() - philosopher->data->birth,
		philosopher->philo_id, "is eating");
	pthread_mutex_unlock(&philosopher->meal_lock);
}

void	finish_eating(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->meal_lock);
	philosopher->has_eaten++;
	if (philosopher->has_eaten == philosopher->data->number_of_meals)
		philosopher->eaten_enough = 1;
	pthread_mutex_unlock(&philosopher->meal_lock);
}

void	eating(t_philo *philosopher)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	fork_order(philosopher, &first_fork, &second_fork);
	take_forks(philosopher, first_fork, second_fork);
	start_eating(philosopher);
	time_to(philosopher->data->time_to_eat);
	finish_eating(philosopher);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}
