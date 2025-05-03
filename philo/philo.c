/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:41:56 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/02 16:37:13 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philosopher[i].thread_id, NULL) != 0)
		{
			printf("Error: Failed to join thread\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	created_thread(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	pthread_mutex_init(&data->output, NULL);
	pthread_create(&monitor_thread, NULL, &monitor, data);
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philosopher[i].thread_id, NULL, &routine,
				&data->philosopher[i]) != 0)
		{
			printf("Error: Failed to create thread\n");
			return (0);
		}
		i++;
	}
	join_thread(data);
	pthread_join(monitor_thread, NULL);
	pthread_mutex_destroy(&data->output);
	return (1);
}

int	handle_errors(char **str, int argc, char **argv)
{
	if (!check_arguments(argc, argv))
	{
		free(str);
		return (0);
	}
	return (1);
}

int	process_arguments(char **str, int argc, char **argv)
{
	str = handle_multiple_arguments(argc, argv);
	if (!*str)
	{
		printf("Error: Argument handling failed\n");
		return (0);
	}
	check_error(str);
	if (!handle_errors(str, argc, argv))
		return (0);
	free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**str;
	t_data	data;

	str = NULL;
	if (argc != 6 && argc != 5)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (!process_arguments(str, argc, argv))
		return (1);
	initialize_data(&data, argc, argv);
	initialize_philosophers(&data);
	created_thread(&data);
	free(str);
	return (0);
}
