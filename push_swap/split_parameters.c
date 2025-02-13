/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:30:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/12 10:09:13 by wlarbi-a         ###   ########.fr       */
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


int	main(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	int k;
	k = ft_atoi(av[j]);
	if (ac >= 2)
	{
		while(av[i] != NULL)
		{
			j = 0;
			while(av[i][j] != '\0')
			{
				k = ft_atoi(av[j]);
				ft_printf("%d\n", k);
				//ft_putnbr(k);
				// else
				// {
				// 	ft_printf("Error, has to be a number");
				// 	return(0);
				// }
				j++;
			}
			i++;
		}
	}
}
