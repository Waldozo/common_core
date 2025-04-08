/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:02:53 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:23 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_for_three(t_lst **a, t_list **c)
{
	if ((*a)->content < (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		reverse_rotate_a(a, c);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
		swap_a(a, c);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		rotate_a(a, c);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
	{
		swap_a(a, c);
		reverse_rotate_a(a, c);
	}
	else if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		swap_a(a, c);
		rotate_a(a, c);
	}
}

void	for_two(t_lst **a, t_list **c)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(a, c);
}

void	ft_pushb(t_lst **a, t_lst **b, t_list **c)
{
	int	median;
	int	i;

	i = 1;
	median = mid_value(*a);
	while (ft_lstsize_bis(*a) > 3)
	{
		while (ft_min(*a) < median * i)
		{
			if ((*a)->content < median * i)
				push_b(a, b, c);
			else
				rotate_a(a, c);
		}
		i++;
		while (i > 3 && ft_lstsize_bis(*a) > 3)
			push_b(a, b, c);
	}
	if (ft_lstsize_bis(*a) == 3)
		ft_for_three(a, c);
}

void	ft_push_lowest_cost(t_lst **a, t_lst **b, t_list **c, int lim)
{
	t_lst	*lowest_cost_node;
	int		rev;
	int		rev_2;

	ft_gettarget(a, b);
	ft_calculate_cost(*a, *b);
	lowest_cost_node = ft_find_lowest_cost(b, lim);
	rev_2 = swp_rev(*b, lowest_cost_node->content, ft_lstsize_bis(*b));
	while ((*b) != lowest_cost_node)
	{
		if (rev_2 == 0)
			rotate_b(b, c);
		else if (rev_2 == 1)
			reverse_rotate_b(b, c);
	}
	rev = swp_rev(*a, (*b)->target, ft_lstsize_bis(*a));
	while ((*b)->target != (*a)->content)
	{
		if (rev == 0)
			rotate_a(a, c);
		else if (rev == 1)
			reverse_rotate_a(a, c);
	}
	push_a(a, b, c);
}

void	ft_sort(t_lst **a, t_lst **b, t_list **c)
{
	int	rev;
	int	lim;

	rev = 0;
	lim = mid_value(*b);
	while ((*b) && ft_max(*b) >= lim)
	{
		get_index(*b);
		ft_push_lowest_cost(a, b, c, lim);
	}
	while (*b)
	{
		get_index(*b);
		ft_push_lowest_cost(a, b, c, lim);
	}
	rev = swp_rev(*a, ft_min(*a), ft_lstsize_bis(*a));
	while ((*a)->content != ft_min(*a))
	{
		if (rev == 0)
			rotate_a(a, c);
		else if (rev == 1)
			reverse_rotate_a(a, c);
	}
}
