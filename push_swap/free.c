/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:29:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 16:06:11 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_free_tab(char **tab)
{
	int	i;
	int	size;

	i = 0;
	size = ft_size_tab(tab);
	while (i < size)
		free(tab[i++]);
	free(tab);
}

int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
		return (i + 1);
	}
	return (0);
}
