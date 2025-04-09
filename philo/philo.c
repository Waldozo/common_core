/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:41:56 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/09 19:18:11 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	**handle_multiple_arguments(int ac, char **argv)
{
	char	**str;
	int		i;

	str = malloc(sizeof(char *) * ac);
	if (!str)
		return (NULL);
	i = 0;
	while (i < ac - 1)
	{
		str[i] = ft_strdup(argv[i + 1]);
		if (!str[i])
		{
			while (i >= 0)
				free(str[i--]);
			free(str);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	*test(void *arg)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < 1000)
	{
		pthread_mutex_lock(&philo.write_lock);
		i++;
		pthread_mutex_unlock(&philo.write_lock);
	}
	pthread_exit(EXIT_SUCCESS);
}

int	created_thread(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_init(&philo->write_lock, NULL);
	while (i <= philo->number_of_philosophers)
	{
		if (pthread_create(&philo->thread[i], NULL, &test, NULL) != 0)
		{
			printf("Error creating thread\n");
			return (0);
		}
		printf("thread %d has started\n", i);
		printf("thread %d has finished\n", i);
		i++;
	}
	while (i < philo->number_of_philosophers)
	{
		if (pthread_join(philo->thread[i], NULL) != 0)
		{
			printf("Error joining thread\n");
			return (0);
		}
		i++;
	}
	pthread_mutex_destroy(&philo->write_lock);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;
	t_philo	philo;

	str = NULL;
	if (argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (argc == 6)
	{
		str = handle_multiple_arguments(6, argv);
        check_arguments(argv);
        check_error(str);
        initialize_philosophers(&philo, atoi(argv[1]));
		initialize_time_to_die(&philo, atoi(argv[2]));
		initialize_time_to_eat(&philo, atoi(argv[3]));
		initialize_time_to_sleep(&philo, atoi(argv[4]));
		created_thread(&philo);
	}
}
