/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:19:11 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/14 17:45:37 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotone(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 122 || str[i] == 90)
		{
			str[i] = str[i] - 25;
			write(1, &str[i], 1);
		}
		else if ((str[i] >= 65 && str[i] < 90) || (str[i] >= 97
					&& str[i] < 122))
		{
			str[i] = str[i] + 1;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	//	if (argc != 2)
	//		write(1, "\n", 2);
	if (argc == 2)
	{
		rotone(&argv[1][i]);
		write(1, "\n", 1);
	}
	return (0);
}
