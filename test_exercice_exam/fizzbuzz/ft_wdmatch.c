/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:42:57 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/07/18 16:10:09 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
int	ft_len(char *s1)
{
	int i;
	i = 0;
	while(s1[i])
	{
		i++;
	}
	return (i);
}
void	ft_wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
		{	
			i++;
			j++;
		}
		else if (s1[i] != s2[j])
		{
		
			j++;
		}
	}
	if(s1[i] == '\0')
	{
		write(1, s1, ft_len(s1));
	}
}

int	main(int ac, char **av)
{
	int	i;
	i = 0;
	if (ac == 3)
	{
		ft_wdmatch(av[1], av[2]);
	}
}
