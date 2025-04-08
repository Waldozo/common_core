/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:21:18 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/08 21:07:32 by wlarbi-a         ###   ########.fr       */
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
	pthread_t		thread; 
	int				number_of_philosophers;
	int time_to_die;   // in milliseconds
	int time_to_eat;   // in milliseconds
	int time_to_sleep; // in milliseconds
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	long			last_meal_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	struct philo	*next;
}					t_philo;

int					pthread_join(pthread_t thread, void **retval);// bloque le thread appelant jusqu'à ce que le thread spécifié se termine
int					pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr); // initialise un mutex
int					pthread_mutex_destroy(pthread_mutex_t *mutex);// détruit un mutex
int					pthread_mutex_lock(pthread_mutex_t *mutex);// verrouille un mutex
int					pthread_mutex_unlock(pthread_mutex_t *mutex);// déverrouille un mutex
int					pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); // crée un thread
int					pthread_detach(pthread_t thread);// détache un thread
// int gettimeofday(struct timeval *tv, struct timezone *tz); // obtient l'heure actuelle

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
int check_arguments(char **argv);
#endif