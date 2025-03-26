/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:02:53 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/26 17:48:49 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void	ft_for_two(t_lst *lst)
// {
// 	if (ft_lstsize_bis(lst) == 2)
// 	{
// 		if (lst->content > lst->next->content)
// 			swap_a(&lst);
// 	}
// }

void	ft_for_three(t_lst *a)
{

    if (a->content < a->next->content && a->content > a->next->next->content)
		reverse_rotate_a(&a);
	else if (a->content > a->next->content
		&& a->content < a->next->next->content)
		swap_a(&a);
	else if (a->content > a->next->content
		&& a->next->content < a->next->next->content)
		rotate_a(&a);
	else if (a->content > a->next->content
		&& a->content > a->next->next->content)
	{
		swap_a(&a);
		reverse_rotate_a(&a);
	}
	else if (a->content < a->next->content
		&& a->next->content > a->next->next->content)
	{
		swap_a(&a);
		rotate_a(&a);
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

void	ft_pushb(t_lst **a, t_lst **b, int size)
{
	int push;

	push = 0;
	ft_index(*a);
	while (size > 6 && push < size * 2 / 3)
	{
		if ((*a)->index <= size / 3)
		{
			push_b(a, b);
			rotate_b(b);
			push++;
		}
		else if ((*a)->index <= size * 2 / 3)
		{
			push_b(a, b);
			push++;
		}
		else
			rotate_a(a);
	}
	while (size - push > 3)
	{
		push_b(a, b);
		push++;
	}
    if (size - push == 3)
	    ft_for_three(*a);
}


// Fonction pour calculer la cible de chaque élément de b
void	ft_gettarget(t_lst **a, t_lst **b)
{
    t_lst	*tmp_b;
    t_lst	*tmp_a;
    int		target;

    tmp_b = *b;
    while (tmp_b)
    {
        tmp_a = *a;
        target = ft_max(*a);
        while (tmp_a)
        {
            if (tmp_a->content > tmp_b->content && tmp_a->content < target)
                target = tmp_a->content;
            tmp_a = tmp_a->next;
        }
        // if (target == ft_max(*a))
        //     target = ft_min(*a);
        tmp_b->target = target;
        tmp_b = tmp_b->next;
    }
}

// Fonction pour calculer le coût de déplacement de chaque élément de b
void	ft_calculate_cost(t_lst **a, t_lst **b)
{
    t_lst	*tmp_b;
    int		size_a;
    int		size_b;

    size_a = ft_lstsize_bis(*a);
    size_b = ft_lstsize_bis(*b);
    printf("size_a = %d\n", size_a);
    printf("size_b = %d\n", size_b);
    tmp_b = *b;
    while (tmp_b)
    {
        tmp_b->cost_b = tmp_b->index;
        if (tmp_b->index > size_b / 2)
            tmp_b->cost_b = size_b - tmp_b->index;
        tmp_b->cost_a = 0;
        t_lst *tmp_a = *a;
        while (tmp_a)
        {
            if (tmp_a->content == tmp_b->target)
                break;
            tmp_b->cost_a++;
            tmp_a = tmp_a->next;
        }
        if (tmp_b->cost_a > size_a / 2)
            tmp_b->cost_a = size_a - tmp_b->cost_a;
        tmp_b->total_cost = tmp_b->cost_a + tmp_b->cost_b;
        tmp_b = tmp_b->next;
    }
}

// Fonction pour trouver l'élément de b avec le coût le plus bas
t_lst	*ft_find_lowest_cost(t_lst **b)
{
    t_lst	*tmp_b;
    t_lst	*lowest_cost_node;

    tmp_b = *b;
    lowest_cost_node = tmp_b;
    while (tmp_b)
    {
        if (tmp_b->total_cost <= lowest_cost_node->total_cost)
            lowest_cost_node = tmp_b;
        tmp_b = tmp_b->next;
    }
    return (lowest_cost_node);
}

// Fonction principale pour pousser l'élément avec le coût le plus bas de b vers a
void	ft_push_lowest_cost(t_lst **a, t_lst **b)
{
    t_lst	*lowest_cost_node;
  
    ft_gettarget(a, b);
    ft_calculate_cost(a, b);
    lowest_cost_node = ft_find_lowest_cost(b);
    while (*b != lowest_cost_node)
    {
        if (lowest_cost_node->index > ft_lstsize_bis(*b) / 2)
            rotate_b(b);
        else if(lowest_cost_node->index <= ft_lstsize_bis(*b) / 2)
            reverse_rotate_b(b);
    }
    push_a(a, b);
}

// Fonction pour trier la pile a en utilisant les éléments de b
void	ft_sort(t_lst **a, t_lst **b)
{
    while (*b)
        ft_push_lowest_cost(a, b);
}