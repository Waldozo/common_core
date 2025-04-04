/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:02:53 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/04 23:14:50 by wlarbi-a         ###   ########.fr       */
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
	long	result;
	long	rslt;

	size = 0;
	result = 0;
	while (a)
	{
		result += a->content;
		size++;
		a = a->next;
	}
	rslt = result / size;
	return ((int)rslt / 2);
}

// void	ft_pushb(t_lst **a, t_lst **b, t_list **c, int size)
// {
// 	int	mid;

// 	mid = mid_value(*a);
// 	size = ft_lstsize_bis(*a);
// 	ft_index(*a);
// 	printf
// 	while (ft_min(*a) <= mid)
// 	{
// 		if ((*a)->content <= mid * 2 / 3)
// 		{
// 			push_b(a, b, c);
// 			rotate_b(b, c);
// 		}
// 		else if ((*a)->content <= mid * 4/3)
// 			push_b(a, b, c);
// 		else
// 			rotate_a(a, c);
// 	}
// 	while (ft_lstsize_bis(*a) > 3)
// 	{
// 		push_b(a, b, c);
// 		size--;
// 	}
// 	if (ft_lstsize_bis(*a) == 3)
// 		ft_for_three(a, c);
// }

void	ft_pushb(t_lst **pile_a, t_lst **pile_b, t_list **result)
{
	int	median;
	int	i;

	i = 1;
	median = mid_value(*pile_a);
	while (ft_lstsize_bis(*pile_a) > 3 )
	{
		while (ft_min(*pile_a) < median * i)
		{
			if ((*pile_a)->content < median * i)
				push_b(pile_a, pile_b, result);
			else
				rotate_a(pile_a, result);
		}
		i++;
		while (i > 3 && ft_lstsize_bis(*pile_a) > 3)
			push_b(pile_a, pile_b, result);
	}
	if (ft_lstsize_bis(*pile_a) == 3)
		ft_for_three(pile_a, result);
	if (*pile_b)
		ft_sort(pile_a, pile_b, result);
}
// void	ft_pushb(t_lst **a, t_lst **b, t_list **c, int size)
// {
// 	int push;

// 	if (ft_lstsize_bis(*a) == 3)
// 		push = 0;
// 	ft_index(*a);
// 	while (size > 6 && push < size * 2 / 3)
// 	{
// 		if ((*a)->index <= size / 3)
// 		{
// 			push_b(a, b, c);
// 			rotate_b(b, c);
// 			push++;
// 		}
// 		else if ((*a)->index <= size * 2 / 3)
// 		{
// 			push_b(a, b, c);
// 			push++;
// 		}
// 		else
// 			rotate_a(a, c);
// 	}
// 	// while (size - push > 3)
// 	// {
// 	// 	push_b(a, b, c);
// 	// 	push++;
// 	// }
// 	// if (size - push == 3)
// 	// 	ft_for_three(a, c);
// }

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
	while (ft_max(*b) > lim)
	{
		get_index(*b);
		ft_push_lowest_cost(a, b, c, lim);
	}
	lim = mid_value(*b);
	while (ft_max(*b) > lim)
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

int	swp_rev(t_lst *a, int element, int size)
{
	int		i;
	t_lst	*tmp;

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

void	swp_is_both(t_list *lst, char *content, char *target, char *replace)
{
	t_list	*first;
	t_list	*temp;

	first = lst;
	while (lst->next && ft_strncmp(content, lst->next->content, 4) == 0)
		lst = lst->next;
	if (lst->next && ft_strncmp(target, lst->next->content, 4) == 0)
	{
		free(first->content);
		first->content = ft_strdup(replace);
		temp = lst->next;
		if (lst->next->next)
			lst->next = lst->next->next;
		else
			lst->next = NULL;
		ft_lstdelone(temp, swp_del);
	}
}

void	swp_check_both(t_list *lst)
{
	while (lst)
	{
		if (ft_strncmp(lst->content, "sa", 3) == 0)
			swp_is_both(lst, "sa", "sb", "ss");
		else if (ft_strncmp(lst->content, "sb", 3) == 0)
			swp_is_both(lst, "sb", "sa", "ss");
		else if (ft_strncmp(lst->content, "ra", 3) == 0)
			swp_is_both(lst, "ra", "rb", "rr");
		else if (ft_strncmp(lst->content, "rb", 3) == 0)
			swp_is_both(lst, "rb", "ra", "rr");
		else if (ft_strncmp(lst->content, "rra", 4) == 0)
			swp_is_both(lst, "rra", "rrb", "rrr");
		else if (ft_strncmp(lst->content, "rrb", 4) == 0)
			swp_is_both(lst, "rrb", "rra", "rrr");
		lst = lst->next;
	}
}

void	swp_lstprinter(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
		ft_putendl_fd(lst->content, 1);
	}
}

void	swp_lstprint(t_list *result)
{
	swp_check_both(result);
	swp_lstprinter(result);
}

void	swp_del(void *content)
{
	free(content);
}

void	free_list(t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	free_list_bis(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
}