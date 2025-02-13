/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:18:31 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/28 11:26:46 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
int	len(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	int		s;

	s = 0;
	i = len(nbr);
	str = malloc((i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nbr == -2147483648)
	{
		str = "-2147483648";
	}
	else if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[--i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int	nbr;

	nbr = -22;
	printf("%s", ft_itoa(nbr));
}