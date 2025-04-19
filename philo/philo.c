/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:41:56 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/19 19:49:45 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	created_thread(t_data *data)
{
	int	i;
	pthread_t monitor_thread;

	i = 0;
	pthread_mutex_init(&data->output, NULL);
	pthread_create(&monitor_thread, NULL, &monitor, data);
	while (i < data->number_of_philosophers)
	{
		if(pthread_create(&data->philosopher[i].thread_id, NULL, &routine,
			&data->philosopher[i]) != 0)
		{
			printf("Error: Failed to create thread\n");
			return (0);
		}
		i++;
	}
	while (--i >= 0)
	{
		if(pthread_join(data->philosopher[i].thread_id, NULL) != 0)
		{
			printf("Error: Failed to join thread\n");
			return (0);
		}
	}
	pthread_join(monitor_thread, NULL);
	pthread_mutex_destroy(&data->output);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**str;
	t_data	*data;
	
	str = NULL;
	if (argc != 6 && argc != 5)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	str = handle_multiple_arguments(argc, argv);
	if (!str)
	{
		printf("Error: Argument handling failed\n");
		free(data);
		return (1);
	}
	if (!check_arguments(argc, argv))
	{
		printf("Error: Invalid arguments\n");
		free(str);
		free(data);
		return (1);
	}
	check_error(str);
	initialize_data(data, argc, argv);
	initialize_philosophers(data);
	created_thread(data);
	free(str);
	free(data);
	return (0);
}

long long its_time(int t)
{
	return(time_to(t) + timeoftheday());
}

long long time_to(int time)
{
	usleep(time * 1000);
	return(time * 1000);
}