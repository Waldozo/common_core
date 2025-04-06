/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:31:11 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 16:05:46 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swp_lstprint(t_list *c)
{
	swp_check_both(c);
	swp_lstprinter(c);
}
