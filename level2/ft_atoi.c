/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:34:07 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/20 13:53:43 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	r;

	r = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		signe = -1;
	// if (str[i] == '+' || str[i] == '-')
	// 	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * signe);
}

#include <stdio.h>

int	main(void)
{
	const char	*str;

	str = "-1";
	printf("%d", ft_atoi(str));
}
