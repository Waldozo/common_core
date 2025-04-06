/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:18:33 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 16:29:58 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew_bis(int content)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back_bis(t_lst **lst, t_lst *new)
{
	t_lst	*slt;

	slt = NULL;
	if (*lst)
	{
		slt = ft_lstlast_bis(*lst);
		slt->next = new;
	}
	else
		*lst = new;
}

t_lst	*ft_lstlast_bis(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize_bis(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstdelone_bis(t_lst *lst, void (*del)(void *))
{
	(del)(lst->content_bis);
	free(lst);
}
