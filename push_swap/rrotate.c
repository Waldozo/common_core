/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:12:07 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/24 11:28:27 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_lst **a)
{
	t_lst	*temp;
	t_lst	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next->next != NULL)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *a;
	*a = temp;
	printf("rra\n");
}

void	reverse_rotate_b(t_lst **b)
{
	t_lst	*temp;
	t_lst	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	while (last->next->next != NULL)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *b;
	*b = temp;
	printf("rrb\n");
}

void	reverse_rotate_ab(t_lst **a, t_lst **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	printf("rrr\n");
}
