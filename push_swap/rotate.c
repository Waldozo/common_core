/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:11:21 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/04 21:40:13 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	rotate_a(t_lst **a, t_list **c)
{
	t_lst	*temp;
	t_lst	*last;
	
	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	last = ft_lstlast_bis(*a);
	last->next = temp;
	temp->next = NULL;
	ft_lstadd_back(c, ft_lstnew(ft_strdup("ra")));
}

void	rotate_b(t_lst **b, t_list **c)
{
	t_lst	*temp;
	t_lst	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	last = ft_lstlast_bis(*b);
	last->next = temp;
	temp->next = NULL;
	ft_lstadd_back(c, ft_lstnew(ft_strdup("rb")));
}

// void	rotate_ab(t_lst **a, t_lst **b)
// {
// 	rotate_a(a);
// 	rotate_b(b);
// 	printf("rr\n");
// }
