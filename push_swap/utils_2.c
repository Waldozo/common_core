/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:20:30 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 21:55:50 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_lst *a)
{
	int	max;

	max = a->content;
	while (a)
	{
		if (max < a->content)
			max = a->content;
		a = a->next;
	}
	return (max);
}

int	ft_min(t_lst *a)
{
	int	min;

	min = a->content;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	return (min);
}

int	mid_value(t_lst *a)
{
	long	size;
	long	c;
	long	rslt;

	size = 0;
	c = 0;
	while (a)
	{
		c += a->content;
		size++;
		a = a->next;
	}
	rslt = c / size;
	return ((int)rslt / 2);
}

t_lst	*process_list(char **str)
{
	int		i;
	t_lst	*lst;
	t_lst	*tmp;

	i = 0;
	lst = NULL;
	while (str[i] != NULL)
	{
		if (!lst)
			lst = ft_lstnew_bis(ft_atoi(str[i]));
		else
		{
			tmp = ft_lstnew_bis(ft_atoi(str[i]));
			ft_lstadd_back_bis(&lst, tmp);
		}
		i++;
	}
	return (lst);
}

void	printf_list(t_lst **a, t_list *c, t_lst *b)
{
	if (ft_lstsize_bis(*a) == 2)
		for_two(a, &c);
	if (ft_lstsize_bis(*a) == 3 && swp_order(*a) == 1)
		ft_for_three(a, &c);
	if (ft_lstsize_bis(*a) > 5 && swp_order(*a) == 1)
	{
		ft_pushb(a, &b, &c);
		ft_sort(a, &b, &c);
	}
	if ((ft_lstsize_bis(*a) == 5 || ft_lstsize_bis(*a) == 4)
		&& swp_order(*a) == 1)
	{
		while (ft_lstsize_bis(*a) > 3)
			push_b(a, &b, &c);
		ft_for_three(a, &c);
		ft_sort(a, &b, &c);
	}
}
