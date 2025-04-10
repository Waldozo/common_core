/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:10:33 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 18:42:25 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_lst **a, t_list **c)
{
	t_lst	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	ft_lstadd_back(c, ft_lstnew(ft_strdup("sa")));
}

void	swap_b(t_lst **b, t_list **c)
{
	t_lst	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	ft_lstadd_back(c, ft_lstnew(ft_strdup("sb")));
}

void	swap_ab(t_lst **a, t_list **b)
{
	swap_a(a, b);
	swap_b(a, b);
}
