/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:30:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/19 15:55:40 by wlarbi-a         ###   ########.fr       */
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
	return (1);
}

int main(int ac, char **argv)
{
	int i = 0;
	int j = i + 1;
	char **str;
	
	if (ac < 2)
		return (0);
	if (ac == 2)
	{	
		str = ft_split(argv[1], ' ');
		while(str[i])
		{
			j = i + 1;
			while(str[j])
			{
				if(str[j] == str[i])
				{
					printf("Error\n");
					return (0);
				}
				j++;
			}
			i++;
		}
		i = 0;
		while(str[i])
		{
			if(isnum(str[i]) == 0)
			{
				printf("Error\n");
				return (0);
			}
			else if(isnum(str[i]) == 1)
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
	}
}