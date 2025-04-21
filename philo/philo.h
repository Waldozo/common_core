/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:21:18 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/21 18:49:28 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				philo_id;
	int				eat;
	long long		last_meal;
	int				meals_eaten;
	int				eaten_enough;
	int				has_eaten;

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write;
	pthread_t		thread_id;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	meal_lock;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				is_dead;
	long long		birth;
	t_philo			philosopher[200];
	long long		time;
	pthread_mutex_t	ate_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	eat;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	output;
}					t_data;

size_t				ft_strlen(const char *c);
int					isnum(char *str);
long				ft_atol(char *str);
int					check_isnum(char **str);
int					check_limits(char **str);
int					check_error(char **str);
char				**handle_multiple_arguments(int ac, char **argv);

void				initialize_philosophers(t_data *data);
int					created_thread(t_data *data);
int					initialize_data(t_data *data, int argc, char **argv);

int					check_arguments(int argc, char **argv);
int					check_arguments_1(char **argv);
int					check_arguments_2(char **argv);

long long			timeoftheday(void);
void				output(t_data *data, int time, int philo_id, char *message);
void				eating(t_philo *philosopher);
void				thinking(t_philo *philosopher);
void				sleeping(t_philo *philosopher);
void				*routine(void *arg);
long long			time_to(int time);
void				*monitor(void *arg);

void				ft_free_tab(char **tab);
int					ft_size_tab(char **tab);
#endif