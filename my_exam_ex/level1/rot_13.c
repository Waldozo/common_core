/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:00:13 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/16 09:36:30 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] <= 77 && str[i] >= 65) || (str[i] <= 109 && str[i] >= 97))
		{
			str[i] = str[i] + 13;
			write(1, &str[i], 1);
		}
		else if ((str[i] <= 90 && str[i] >= 78) || (str[i] <= 122
					&& str[i] >= 110))
		{
			str[i] = str[i] - 13;
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
	if (argc == 2)
	{
		rot_13(&argv[1][i]);
	}
}
