/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:49:25 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/07/18 18:03:36 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
	
}
void	ft_putnbr(int nb)
{
	long	i;
	i = nb;

	if (i < 0)
	{
		i = -i;
		write(1, "-", 1);
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
}

int	main(void)
{
	int	nb = 0;
	ft_putnbr(nb);
}
