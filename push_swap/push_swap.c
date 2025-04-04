/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:20:30 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/04 19:57:42 by wlarbi-a         ###   ########.fr       */
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
			// printf("%d\n", tmp->content);
        }
		i++;
	}
    return(lst);
}

void printf_list(t_lst *lst, t_list *c)
{
	t_lst *b;
	b = NULL;
	ft_pushb(&lst, &b, &c, ft_lstsize_bis(lst));
	ft_sort(&lst, &b, &c);
}

