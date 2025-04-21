/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:47:09 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/21 15:05:40 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philosopher_death(t_data *data, int i, long long current_time)
{
	long long	time_since_last_meal;

	pthread_mutex_lock(&data->philosopher[i].meal_lock);
	time_since_last_meal = current_time - data->philosopher[i].last_meal;
	pthread_mutex_unlock(&data->philosopher[i].meal_lock);
	if (time_since_last_meal > data->time_to_die)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (!data->is_dead)
		{
			data->is_dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			output(data, current_time - data->birth,
				data->philosopher[i].philo_id, "died");
			return (1);
		}
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}

int	check_all_eaten(t_data *data, int i)
{
	int	meals_eaten;

	pthread_mutex_lock(&data->philosopher[i].meal_lock);
	meals_eaten = data->philosopher[i].has_eaten;
	pthread_mutex_unlock(&data->philosopher[i].meal_lock);
	if (data->number_of_meals != -1 && meals_eaten < data->number_of_meals)
		return (0);
	return (1);
}

void	end_simulation(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->dead_lock);
}

int	check_all_philosophers(t_data *data, long long current_time, int *all_eaten)
{
	int	i;

	i = 0;
	*all_eaten = 1;
	while (i < data->number_of_philosophers)
	{
		if (check_philosopher_death(data, i, current_time))
			return (1);
		if (!check_all_eaten(data, i))
			*all_eaten = 0;
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data		*data;
	int			all_eaten;
	long long	current_time;

	data = (t_data *)arg;
	while (1)
	{
		current_time = timeoftheday();
		if (check_all_philosophers(data, current_time, &all_eaten))
			return (NULL);
		if (all_eaten && data->number_of_meals != -1)
		{
			end_simulation(data);
			break ;
		}
		usleep(2000);
	}
	return (NULL);
}
