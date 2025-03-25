/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:20:30 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/25 17:38:49 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*process_list(char **str)
{
	int		i;
	t_lst	*lst;
    t_lst   *tmp;

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
    return(lst);
}

void printf_list(t_lst *lst)
{
	// t_lst *b;
	// b = NULL;
	
	ft_max(lst);
	// ft_turc(lst, &b);
	//ft_for_two(lst);
	// ft_index(lst);
	// ft_for_three(lst);
	// while(b)
	// {
	// 	printf("b->content = %d\n", (b)->content);
	// 	b = b->next;
	// }
    // while(lst)
    // {
    //     printf("lst->content = %d\n", lst->content);
    //     lst = lst->next;
    // }
    // printf("end\n");
}