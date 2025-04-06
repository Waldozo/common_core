/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:38:37 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 15:41:31 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_lst **a, t_lst **b, t_list **c)
{
	t_lst	*temp;
	t_lst	*tmp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	tmp = *b;
	*b = temp;
	temp->next = tmp;
	ft_lstadd_back(c, ft_lstnew(ft_strdup("pb")));
}

void	push_a(t_lst **a, t_lst **b, t_list **c)
{
	t_lst	*temp;
	t_lst	*tmp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	tmp = *a;
	*a = temp;
	temp->next = tmp;
	ft_lstadd_back(c, ft_lstnew(ft_strdup("pa")));
}
