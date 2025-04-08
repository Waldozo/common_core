/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:41:56 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/08 21:04:02 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

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

int check_arguments(char **argv)
{
    if(atol(argv[1]) <= 0 || atol(argv[1]) > 200)
    {
        printf("Error: the number of philosophers should be bigger than 0\n");
        return (1);
    }
    if(atol(argv[2]) <= 0)
    {
        printf("Error, the time to die should be bigger than 0\n");
        return (1);
    }
    if(atol(argv[3]) <= 0)
    {
        printf("Error, the time to eat should be bigger than 0\n");
        return (1);
    }
    if(atol(argv[4]) <= 0)
    {
        printf("Error, the time to sleep should be bigger than 0\n");
        return (1);
    }
    if(atol(argv[5]) <= 0)
    {
        printf("Error, the number of meals should be bigger than 0\n");
        return (1);
    }
    return(0);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    char **str;
    str = NULL;

    if(argc != 6)
    {
        printf("Error: Wrong number of arguments\n");
        return (1);
    }
    
    if(argc == 6)
    {
        str = handle_multiple_arguments(6, argv);
        check_arguments(argv);
        check_error(str);
    }
}