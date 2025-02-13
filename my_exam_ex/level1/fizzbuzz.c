/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:22:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/22 10:29:52 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
void	putnbr(int nb)
{
	char	i;

	if (nb < 10)
	{
		i = nb + '0';
		write(1, &i, 1);
	}
	else if (nb >= 10)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
}

int	main(void)
{
	int	a;

	a = 1;
	while (a <= 100)
	{
		if (a % 3 == 0 && a % 5 == 0)
		{
			write(1, "fizzbuzz\n", 10);
		}
		else if (a % 3 == 0)
		{
			write(1, "fizz\n", 6);
		}
		else if (a % 5 == 0)
		{
			write(1, "buzz\n", 6);
		}
		else
		{
			putnbr(a);
			write(1, "\n", 2);
		}
		a++;
	}
}
