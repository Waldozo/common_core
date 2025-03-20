/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:30:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/20 14:38:12 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// output
// swap sa/sb ss
// rotate ra/rb rr
// reverse rotate rra/rrb rrr
// push pa/pb
#include <stdio.h>
#include <stdlib.h>

int isnum(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	// i = 1;
	// while (str[i])
	// {
	// 	if((str[0] == '-') && (str[i] <= '0' && str[i] > '9'))
	// 		return (0);
	// 	i++;
	// }
	return (1);
}

long ft_atol(char *str)
{
	long res = 0;
	int i = 0;
	int sign = 1;
	
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int main(int ac, char **argv)
{
	int i = 0;
	int j = 1;
	char **str;
	
	if (ac < 2)
		return (0);
	if (ac == 2)
	{	
		str = ft_split(argv[1], ' ');
		while(str[i] != NULL)
		{
			j = i + 1;
			while(str[j] != NULL)
			{
				if(ft_atoi(str[j]) == ft_atoi(str[i]))
				{
					printf("Error\n");
					return (0);
				}
				else
					j++;
			}
			if(ft_atol(str[i]) > 2147483647 || ft_atol(str[i]) < -2147483648  || ft_strlen(str[i]) > 11)
			{
				printf("Error\n");
				return (0);
			}
			if(ft_atol(str[i]) == 0 && ft_strlen(str[i]) > 1)
			{
				printf("Error\n");
				return (0);
			}
			if(ft_atol(str[i]) == '-' && ft_strlen(str[i]) < 2)
			{
				printf("Error\n");
				return (0);
			}
			i++;
		}
		i = 0;
		while(str[i])
		{
			if(isnum(str[i]) == 0 && str[i][0] != '-' && str[i][0] != '+')
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			if(str[i][0] == '-' && ft_atoi(str[i]) == '0')
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			if(str[i][0] == '-' && ft_strlen(str[i]) < 2)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			else
			{
				printf("str[%d] = %s\n", i, str[i]);
			}
			i++;
		}
	}
	else
	{
		str = malloc(sizeof(char *) * ac);
		while (i < ac - 1)
		{
			str[i] = argv[i + 1];
			printf("str[%d] = %s\n", i, str[i]);
			i++;
		}
		str[i] = NULL;
		while(str[i] != NULL)
		{
			j = i + 1;
			while(str[j] != NULL)
			{
				if(ft_atoi(str[j]) == ft_atoi(str[i]))
				{
					printf("Error\n");
					return (0);
				}
				else
					j++;
			}
			i++;
		}
	}
}