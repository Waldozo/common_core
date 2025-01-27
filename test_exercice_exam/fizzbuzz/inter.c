/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:49:58 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/07/18 17:42:01 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
int	ft_len(char *s1)
{
	int	i;
	i = 0;
	while(s1[i])
	{
		i++;
	}
	return(i);
}

int	check(char *s1, int i, char c)
{
	int	j;
	j = 0;
	while(j < i)
	{
		if(c == s1[j])
		{
			return(1);
		}
		j++;
	}
	return(0);
}

void inter(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (check(s1, i, s1[i]) == 0 && check(s2, ft_len(s2), s1[i]) == 1)
		{
			write(1, &s1[i], 1);
		}
		i++;
	}
}
#include<stdio.h>
int	main(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ac == 3)
	{
		inter(av[1], av[2]);
	}
}
