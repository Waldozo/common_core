/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:38:07 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/15 11:09:11 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrbase(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbrbase(-n, base) + 1);
	}
	else if (n < base)
	{
		return (ft_putchar(symbols[n]));
	}
	else
	{
		count = ft_putnbrbase(n / base, base);
		return (count + ft_putnbrbase(n % base, base));
	}
}

int	ft_putnbrbase_maj(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbrbase_maj(-n, base) + 1);
	}
	else if (n < base)
	{
		return (ft_putchar(symbols[n]));
	}
	else
	{
		count = ft_putnbrbase_maj(n / base, base);
		return (count + ft_putnbrbase_maj(n % base, base));
	}
}

int	ft_pointer(size_t n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else if (n < (size_t)base)
	{
		ft_putstr("0x");
		ft_putchar(symbols[n]);
		return (3);
	}
	else
	{
		count = ft_pointer(n / (size_t)base, base);
		ft_putchar(symbols[n % (size_t)base]);
		count += 1;
		return (count);
	}
}
