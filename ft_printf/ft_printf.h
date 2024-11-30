/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:20:30 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/11/23 14:40:39 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putnbrbase(long n, int base);
int	ft_putnbrbase_maj(long n, int base);
int	print_format(char sp, va_list ap);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_pointer(size_t n, int base);

#endif