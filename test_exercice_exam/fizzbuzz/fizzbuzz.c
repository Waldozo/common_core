/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:21:27 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/07/11 11:06:58 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb)
{
	char	i;

	if (nb < 10)
	{
		i = nb + '0';
		write(1, &i, 1);
	}
	else if (i >= 10)
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb  % 10);
	}
}

void	ft_fizzbuzz()
{
	int	a;

	a = 0;
	while (a <= 99)
	{
		if (a % 5 == 0 && a % 3 == 0)
		{
			write(1, "FIZZBUZZ\n", 9);
		}
		else if (a % 3 == 0)
		{
			write(1, "FIZZ\n", 5);
		}
		else if (a % 5 == 0)
		{
			write(1, "BUZZ\n", 5);
		}
		else
		{
			ft_putnbr(a);
			write(1, "\n", 1);

		}
		a++;
	}
}

int	main(void)
{
	ft_fizzbuzz();
}
