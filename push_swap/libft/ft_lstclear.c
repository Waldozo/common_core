/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:02:39 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/22 16:02:57 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*s;
	t_list	*slt;

	s = *lst;
	while (s)
	{
		slt = s->next;
		ft_lstdelone(s, del);
		s = slt;
	}
	*lst = NULL;
}
