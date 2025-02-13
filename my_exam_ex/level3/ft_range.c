/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:41:30 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/20 11:59:10 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*s;
	int	i;

	i = 0;
	s = malloc(100000);
	while (i <= start - end)
	{
		s[i] = end + i;
		i++;
	}
	return (s);
}
#include <stdio.h>

int	main(void)
{
	int i;
	int min;
	int max;
	int *tab;

	tab = 0;
	min = 9;
	max = 1;
	tab = ft_range(min, max);
	i = 0;
	if(max > min)
	{
		while (i <= (max - min))
		{
			printf("%d", tab[i]);
			i++;
		}
	}
	else
	{
		while(i <= (min - max))
		{
			printf("%d", tab[i]);
			i++;
		}
	}
	free(tab);
	tab = 0;
	return (0);
}