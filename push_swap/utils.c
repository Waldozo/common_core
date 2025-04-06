/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:04:59 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 19:12:10 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	res;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_index(t_lst *a)
{
	t_lst	*head;
	t_lst	*first;

	head = a;
	first = a;
	while (head)
	{
		head->index = 1;
		while (a)
		{
			if (a->content < head->content)
				head->index += 1;
			a = a->next;
		}
		a = first;
		head = head->next;
	}
}

void	get_index(t_lst *a)
{
	t_lst	*tmp;
	int		index;

	tmp = a;
	index = 1;
	while (tmp)
	{
		tmp->index_b = index;
		index++;
		tmp = tmp->next;
	}
}

int	swp_order(t_lst *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}