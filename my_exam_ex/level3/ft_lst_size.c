/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:44:22 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/10 11:30:13 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int ft_lst_size(t_list *begin_list)
{
    int i;

    i = 1;
    if(!begin_list)
        return(0);
    while(begin_list)
    {
        begin_list = begin_list -> next;
        i++;
    }
    return(i);
}