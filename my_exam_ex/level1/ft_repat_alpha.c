/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repat_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:21:05 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/16 14:06:00 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_repeat_alpha(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0' && str[i] >= 'a' && str[i] <= 'z')
	{
		j = str[i];
		while (j - 97 >= 0)
		{
			write(1, &str[i], 1);
			j--;
		}
		i++;
	}
	while (str[i] != '\0' && str[i] >= 'A' && str[i] <= 'Z')
	{
		j = str[i];
		while (j - 65 >= 0)
		{
			write(1, &str[i], 1);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		ft_repeat_alpha(&argv[1][i]);
	}
	return (0);
}
