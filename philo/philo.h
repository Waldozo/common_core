/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:21:18 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/09 18:58:51 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread[200];
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_eaten;
	long			last_meal_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	struct philo	*next;
}					t_philo;

int					pthread_mutex_init(pthread_mutex_t *mutex,
						const pthread_mutexattr_t *mutexattr);
int					pthread_mutex_destroy(pthread_mutex_t *mutex);
int					pthread_mutex_lock(pthread_mutex_t *mutex);
int					pthread_mutex_unlock(pthread_mutex_t *mutex);
int					pthread_join(pthread_t thread, void **retval);
int					pthread_create(pthread_t *thread,
						const pthread_attr_t *attr,
						void *(*start_routine)(void *), void *arg);
int					pthread_detach(pthread_t thread);

size_t				ft_strlen(const char *c);
int					isnum(char *str);
long				ft_atol(char *str);
int					check_isnum(char **str);
int					check_limits(char **str);
int					check_error(char **str);

static int			strlen_split(const char *s, char c);
static int			count_words_split(char const *s, char c);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *src);
void				initialize_philosophers(t_philo *philo, int c);
int					created_thread(t_philo *philo);
void				initialize_time_to_die(t_philo *philo, int c);
void				initialize_time_to_eat(t_philo *philo, int c);
void				initialize_time_to_sleep(t_philo *philo, int c);
void				initialize_forks(t_philo *philo, int c);

int					check_arguments(char **argv);
int					check_arguments_1(char **argv);
int					check_arguments_2(char **argv);
#endif