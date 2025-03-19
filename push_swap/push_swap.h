/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:41:51 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/17 12:39:23 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
void	ft_putnbr(int nb);
typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;
#endif