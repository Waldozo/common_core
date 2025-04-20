/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:47:09 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/20 22:51:27 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_philosopher_death(t_data *data, int i, long long current_time)
{
    pthread_mutex_lock(&data->philosopher[i].meal_lock);
    long long time_since_last_meal = current_time - data->philosopher[i].last_meal;
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
            return 1;
        }
        pthread_mutex_unlock(&data->dead_lock);
        return 1;
    }
    return 0; 
}

int check_all_eaten(t_data *data, int i)
{
    pthread_mutex_lock(&data->philosopher[i].meal_lock);
    int meals_eaten = data->philosopher[i].has_eaten;
    pthread_mutex_unlock(&data->philosopher[i].meal_lock);
    
    if (data->number_of_meals != -1 && meals_eaten < data->number_of_meals)
        return 0;
    return 1;
}

void end_simulation(t_data *data)
{
    pthread_mutex_lock(&data->dead_lock);
    data->is_dead = 1;
    pthread_mutex_unlock(&data->dead_lock);
}

void *monitor(void *arg)
{
    t_data *data = (t_data *)arg;
    int i;
    int all_eaten;
    long long current_time;
    while (1)
    {
        i = 0;
        all_eaten = 1;
        while (i < data->number_of_philosophers)
        {
            current_time = timeoftheday();
            if (check_philosopher_death(data, i, current_time))
                return NULL;
            if (!check_all_eaten(data, i))
                all_eaten = 0;
            i++;
        }
        if (all_eaten && data->number_of_meals != -1)
        {
            end_simulation(data);
            break;
        }
        usleep(2000);
    }
    return NULL;
}


// void *monitor(void *arg)
// {
//     t_data *data = (t_data *)arg;
//     int i;
//     int all_eaten;
//     long long current_time;

//     while (1)
//     {
//         i = 0;
//         all_eaten = 1;

//         while (i < data->number_of_philosophers)
//         {
//             current_time = timeoftheday();
            
//             pthread_mutex_lock(&data->philosopher[i].meal_lock);
//             long long time_since_last_meal = current_time - data->philosopher[i].last_meal;
//             int meals_eaten = data->philosopher[i].has_eaten;
//             pthread_mutex_unlock(&data->philosopher[i].meal_lock);
            
//             if (data->number_of_meals != -1 && meals_eaten < data->number_of_meals)
//                 all_eaten = 0;

//             if (time_since_last_meal > data->time_to_die)
//             {
//                 pthread_mutex_lock(&data->dead_lock);
//                 if (!data->is_dead)
//                 {
//                     data->is_dead = 1;
//                     pthread_mutex_unlock(&data->dead_lock);
//                     output(data, current_time - data->birth, 
//                            data->philosopher[i].philo_id, "died");
//                     return NULL;
//                 }
//                 pthread_mutex_unlock(&data->dead_lock);
//                 return NULL;
//             }
//             i++;
//         }

//         if (all_eaten && data->number_of_meals != -1)
//         {
//             pthread_mutex_lock(&data->dead_lock);
//             data->is_dead = 1;
//             pthread_mutex_unlock(&data->dead_lock);
//             break;
//         }
        
//         usleep(2000);
//     }

//     return NULL;
// }

// void eating(t_philo *philosopher)
// {
//     pthread_mutex_t *first_fork, *second_fork;

//     if (philosopher->philo_id < (philosopher->philo_id + 1) % philosopher->data->number_of_philosophers)
//     {
//         first_fork = philosopher->l_fork;
//         second_fork = philosopher->r_fork;
//     }
//     else
//     {
//         first_fork = philosopher->r_fork;
//         second_fork = philosopher->l_fork;
//     }
//     pthread_mutex_lock(first_fork);
//     output(philosopher->data, timeoftheday() - philosopher->data->birth,
//         philosopher->philo_id, "has taken a fork");
//     pthread_mutex_lock(second_fork);
//     output(philosopher->data, timeoftheday() - philosopher->data->birth,
//         philosopher->philo_id, "has taken a fork");
//     pthread_mutex_lock(&philosopher->meal_lock);
//     philosopher->last_meal = timeoftheday();
//     output(philosopher->data, timeoftheday() - philosopher->data->birth,
//         philosopher->philo_id, "is eating");
//     pthread_mutex_unlock(&philosopher->meal_lock);
    
//     time_to(philosopher->data->time_to_eat);
    
//     pthread_mutex_lock(&philosopher->meal_lock);
//     philosopher->has_eaten++; 
//     if (philosopher->has_eaten == philosopher->data->number_of_meals)
//         philosopher->eaten_enough = 1;
//     pthread_mutex_unlock(&philosopher->meal_lock);
//     pthread_mutex_unlock(second_fork);
//     pthread_mutex_unlock(first_fork);
// }


void determine_fork_order(t_philo *philosopher, pthread_mutex_t **first_fork, pthread_mutex_t **second_fork)
{
    if (philosopher->philo_id < (philosopher->philo_id + 1) % philosopher->data->number_of_philosophers)
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

void take_forks(t_philo *philosopher, pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
    pthread_mutex_lock(first_fork);
    output(philosopher->data, timeoftheday() - philosopher->data->birth,
        philosopher->philo_id, "has taken a fork");
    pthread_mutex_lock(second_fork);
    output(philosopher->data, timeoftheday() - philosopher->data->birth,
        philosopher->philo_id, "has taken a fork");
}

void start_eating(t_philo *philosopher)
{
    pthread_mutex_lock(&philosopher->meal_lock);
    philosopher->last_meal = timeoftheday();
    output(philosopher->data, timeoftheday() - philosopher->data->birth,
        philosopher->philo_id, "is eating");
    pthread_mutex_unlock(&philosopher->meal_lock);
}

void finish_eating(t_philo *philosopher)
{
    pthread_mutex_lock(&philosopher->meal_lock);
    philosopher->has_eaten++; 
    if (philosopher->has_eaten == philosopher->data->number_of_meals)
        philosopher->eaten_enough = 1;
    pthread_mutex_unlock(&philosopher->meal_lock);
}

void eating(t_philo *philosopher)
{
    pthread_mutex_t *first_fork, *second_fork;
    
    determine_fork_order(philosopher, &first_fork, &second_fork);
    take_forks(philosopher, first_fork, second_fork);
    start_eating(philosopher);
    time_to(philosopher->data->time_to_eat);
    finish_eating(philosopher);
    pthread_mutex_unlock(second_fork);
    pthread_mutex_unlock(first_fork);
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
// void *routine(void *arg)
// {
//     t_philo *philo = (t_philo *)arg;
//     t_data *data = philo->data;

//     if (philo->philo_id % 2)
//         usleep(5000);

//     if (data->number_of_philosophers == 1)
//     {
//         pthread_mutex_lock(philo->l_fork);
//         output(data, timeoftheday() - data->birth, philo->philo_id, "has taken a fork");
//         pthread_mutex_unlock(philo->l_fork);
//         while (1)
//         {
//             pthread_mutex_lock(&data->dead_lock);
//             if (data->is_dead)
//             {
//                 pthread_mutex_unlock(&data->dead_lock);
//                 break;
//             }
//             pthread_mutex_unlock(&data->dead_lock);
//             usleep(1000);
//         }
//         return (NULL);
//     }
//     while (1)
//     {
//         pthread_mutex_lock(&data->dead_lock);
//         if (data->is_dead)
//         {
//             pthread_mutex_unlock(&data->dead_lock);
//             break;
//         }
//         pthread_mutex_unlock(&data->dead_lock);
//         pthread_mutex_lock(&philo->meal_lock);
//         if (data->number_of_meals != -1 && philo->eaten_enough)
//         {
//             pthread_mutex_unlock(&philo->meal_lock);
//             break;
//         }
//         pthread_mutex_unlock(&philo->meal_lock);
//         eating(philo);
//         output(data, timeoftheday() - data->birth, philo->philo_id, "is sleeping");
//         time_to(data->time_to_sleep);
//         output(data, timeoftheday() - data->birth, philo->philo_id, "is thinking");
//         usleep(1000);
//     }
//     return (NULL);
// }


void *handle_single_philosopher(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->l_fork);
    output(data, timeoftheday() - data->birth, philo->philo_id, "has taken a fork");
    pthread_mutex_unlock(philo->l_fork);
    
    while (1)
    {
		pthread_mutex_lock(&data->dead_lock);
        if (data->is_dead)
        {
			pthread_mutex_unlock(&data->dead_lock);
            break;
        }
        pthread_mutex_unlock(&data->dead_lock);
        usleep(1000);
    }
    return (NULL);
}

void *philosopher_life_cycle(t_philo *philo, t_data *data)
{
	while (1)
    {
		pthread_mutex_lock(&data->dead_lock);
        if (data->is_dead)
        {
			pthread_mutex_unlock(&data->dead_lock);
            break;
        }
        pthread_mutex_unlock(&data->dead_lock);
        
        pthread_mutex_lock(&philo->meal_lock);
        if (data->number_of_meals != -1 && philo->eaten_enough)
        {
			pthread_mutex_unlock(&philo->meal_lock);
            break;
        }
        pthread_mutex_unlock(&philo->meal_lock);
        
        eating(philo);
        output(data, timeoftheday() - data->birth, philo->philo_id, "is sleeping");
        time_to(data->time_to_sleep);
        output(data, timeoftheday() - data->birth, philo->philo_id, "is thinking");
        usleep(1000);
    }
    return (NULL);
}

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_data *data = philo->data;

	if (philo->philo_id % 2)
		usleep(5000);
		
	if (data->number_of_philosophers == 1)
		return (handle_single_philosopher(philo, data));
	
	return (philosopher_life_cycle(philo, data));
}
