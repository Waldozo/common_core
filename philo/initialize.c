/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:43:48 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/20 22:34:09 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo nombre_philo temps_a_mourir temps_a_manger temps_a_dormir 

int	initialize_data(t_data *data, int argc, char **argv)
{
	t_philo	*philo;
	data->number_of_philosophers = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->number_of_meals= ft_atol(argv[5]);
	else
		data->number_of_meals = -1;
	data->birth = timeoftheday();
	data->is_dead = 0;
	int i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philosopher[i].meal_lock, NULL);
		data->philosopher[i].has_eaten = 0;
		data->philosopher[i].eaten_enough = 0;
		data->philosopher[i].last_meal = data->birth;
		i++;
	}
	pthread_mutex_init(&data->output, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	return (1);
}
	
void initialize_philosophers(t_data *data)
{
    int i = 0;
    
    data->birth = timeoftheday();
    while (i < data->number_of_philosophers)
    {
        data->philosopher[i].philo_id = i + 1;
        data->philosopher[i].meals_eaten = 0;
        data->philosopher[i].has_eaten = 0;
        data->philosopher[i].eaten_enough = 0;
        data->philosopher[i].data = data;
        data->philosopher[i].last_meal = data->birth;
        data->philosopher[i].l_fork = &data->forks[i];
        data->philosopher[i].r_fork = &data->forks[(i + 1) % data->number_of_philosophers];
        pthread_mutex_init(&data->philosopher[i].meal_lock, NULL);
        i++;
    }
}

void	mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s2[i] == s1[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	output(t_data *data, int time, int philo_id, char *message)
{
	pthread_mutex_lock(&data->dead_lock);
	if (!data->is_dead || (data->is_dead && ft_strcmp(message, "died") == 0))
	{
		pthread_mutex_lock(&data->output);
		printf("%05d %d %s\n", time, philo_id, message);
		pthread_mutex_unlock(&data->output);
	}
	pthread_mutex_unlock(&data->dead_lock);
}

long long	timeoftheday(void)
{
	struct timeval	time;
	long long		current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}
