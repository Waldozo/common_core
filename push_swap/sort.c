/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:05:09 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/04 21:52:29 by wlarbi-a         ###   ########.fr       */
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
	int		size_a;
	int		size_b;
	
	tmp_a = a;
	size_a = ft_lstsize_bis(a);
	size_b = ft_lstsize_bis(b);
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
		if (swp_rev(a, tmp_b->target, ft_lstsize_bis(a))== 1)
			tmp_b->cost_a = size_a - (tmp_b->cost_a + 1);
		tmp_b->total_cost = tmp_b->cost_a + tmp_b->cost_b;
		tmp_b = tmp_b->next;
	}
}

t_lst	*ft_find_lowest_cost(t_lst **b, int lim)
{
	t_lst *tmp_b;
	int	max;
	t_lst *lowest_cost_node;

	tmp_b = *b;
	max = ft_max(*b);
	lowest_cost_node = *b;
	while (lowest_cost_node->content != max)
		lowest_cost_node = lowest_cost_node->next;
	while (tmp_b)
	{
		if (tmp_b->total_cost < lowest_cost_node->total_cost && tmp_b->content >= lim)
			lowest_cost_node = tmp_b;
		tmp_b = tmp_b->next;
	}
	return (lowest_cost_node);
}