/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:29:03 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/05/15 14:24:17 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char sp, va_list ap)
{
	if (sp == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (sp == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (sp == 'd')
		return (ft_putnbrbase((long)va_arg(ap, int), 10));
	else if (sp == 'x')
		return (ft_putnbrbase((long)va_arg(ap, unsigned int), 16));
	else if (sp == 'i')
		return (ft_putnbrbase((long)va_arg(ap, int), 10));
	else if (sp == 'p')
		return (ft_pointer((long)va_arg(ap, void *), 16));
	else if (sp == 'X')
		return (ft_putnbrbase_maj((long)(va_arg(ap, unsigned int)), 16));
	else if (sp == '%')
		return (ft_putchar('%'));
	else if (sp == 'u')
		return (ft_putnbrbase((long)va_arg(ap, unsigned int), 10));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
int main(void)
{
	printf("%d", ft_printf(0));
	return(1);
}