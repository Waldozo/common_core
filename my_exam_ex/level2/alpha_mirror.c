/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:29:25 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/16 09:37:24 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
			{
				argv[1][i] = 90 + 65 - argv[1][i];
				write(1, &argv[1][i], 1);
			}
			else if (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				argv[1][i] = 122 + 97 - argv[1][i];
				write(1, &argv[1][i], 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
