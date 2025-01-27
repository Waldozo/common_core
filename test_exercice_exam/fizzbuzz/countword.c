/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:20:29 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/07/18 16:46:59 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countword(char *str)
{
	int	i;
	i = 0;
	int	n;
	n = 0;
	while(str[i])
	{
		if (!(str[i] == ' '))
		{
			if (str[i+1] == 32 || str[i+1] == '\0')
				n += 1;
		}
		i++;
	}
	return(n);
}
#include<stdio.h>
int	main(void)
{
	char *src = "a";
	
	printf("%d", ft_countword(src));
}
