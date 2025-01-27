/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:51:46 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/07/18 16:53:21 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
int	check_before(char *s1, int i, char c)
{
	int	j;

	j = 0;
	while(j < i)
	{
		if(c == s1[j])
			return (1);
		j++;
	}
	return (0);
}

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

void ft_rev(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (check_before(s1, i, s1[i]) == 0)
			write(1, &s1[i], 1);
		i++;
	}
	
	i = 0;
	while (s2[i])
	{
		if (check_before(s1, ft_len(s1), s2[i]) == 0 && check_before(s2, i, s2[i]) == 0)
			write(1, &s2[i], 1);
		i++;
	}
}
int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
	}
	else
	{
		ft_rev(av[1], av[2]);
	}
}
