/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:15:26 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/20 12:27:41 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
int *ft_rrange(int start, int end)
{
	int	*s;
	int	i;
	int j;
	int n;
	n = (end - start);

	j = 0;
	i = 0;
	if(n < 0)
		n = n * -1;
	s = (int *)malloc(sizeof(int) * n);
	if(end - start > 0)
	{
		while(i <= n)
		{
			s[j] = end - i;
			i++;
			j++;
		}
	}
	else
	{
		while(i <= n)
		{
			s[j] = start - i;
			i++;
			j++;
		}
	}
	return(s);
}
#include<stdio.h>
int main(void)
{
	int i;
	int *prt;

	i = 0;
	prt = ft_rrange(4, -4);
	while(i <= 8)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");
	return (0);
}