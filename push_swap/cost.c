/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:05:09 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 21:01:18 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_gettarget(t_lst **a, t_lst **b)
{
	t_lst	*tmp_b;
	t_lst	*tmp_a;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		tmp_b->target = ft_max(*a);
		if (tmp_b->content > tmp_b->target)
			tmp_b->target = ft_min(*a);
		else
		{
			while (tmp_a)
			{
				if (tmp_a->content > tmp_b->content
					&& tmp_a->content < tmp_b->target)
					tmp_b->target = tmp_a->content;
				tmp_a = tmp_a->next;
			}
		}
		tmp_b = tmp_b->next;
	}
}

void	ft_calculate_cost(t_lst *a, t_lst *b)
{
	t_lst	*tmp_a;
	t_lst	*tmp_b;
	int		size_b;

	tmp_a = a;
	size_b = ft_lstsize_bis(b);
	ft_index(a);
	tmp_b = b;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->index_b;
		if (swp_rev(b, tmp_b->content, ft_lstsize_bis(b)) == 1)
			tmp_b->cost_b = size_b - (tmp_b->index_b + 1);
		tmp_b->cost_a = tmp_b->target;
		while (tmp_a)
		{
			if (tmp_a->content == tmp_b->target)
				break ;
			tmp_b->cost_a++;
			tmp_a = tmp_a->next;
		}
		tmp_b->total_cost = tmp_b->cost_a + tmp_b->cost_b;
		tmp_b = tmp_b->next;
	}
}

t_lst	*ft_find_lowest_cost(t_lst **b, int lim)
{
	t_lst	*tmp_b;
	int		max;
	t_lst	*lowest_cost_node;

	tmp_b = *b;
	max = ft_max(*b);
	lowest_cost_node = *b;
	while (lowest_cost_node->content != max)
		lowest_cost_node = lowest_cost_node->next;
	while (tmp_b)
	{
		if (tmp_b->total_cost <= lowest_cost_node->total_cost
			&& tmp_b->content >= lim)
			lowest_cost_node = tmp_b;
		tmp_b = tmp_b->next;
	}
	return (lowest_cost_node);
}

int	swp_rev(t_lst *a, int element, int size)
{
	t_lst	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp->content != element)
	{
		tmp = tmp->next;
		i++;
	}
	if (i >= (size / 2) + (size % 2))
		return (1);
	return (0);
}
