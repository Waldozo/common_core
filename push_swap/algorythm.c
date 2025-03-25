/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:02:53 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/25 17:46:44 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_index(t_lst *lst)
{
    t_lst   *head;
    t_lst   *first;
    
    head = lst;
    first = lst;
    while(head)
    {
        head->index = 1;
        while(lst)
        {
            if(lst->content < head->content)
                head->index += 1;
            lst = lst->next;
        }
        lst = first;
        head = head->next;
    }
}
// void ft_turc(t_lst *lst, t_lst **b)
// {
//     while(ft_lstsize_bis(lst) != 3)
//     {
//         push_a(&lst, &b);
//     }
// }

void    ft_for_two(t_lst *lst)
{
    if(ft_lstsize_bis(lst) == 2)
    {
        if(lst->content > lst->next->content)
            swap_a(&lst);
    }
}

void    ft_for_three(t_lst *lst)
{
    if(ft_lstsize_bis(lst) == 3)
    {
        if(lst->content < lst->next->content && lst->content > lst->next->next->content)
            reverse_rotate_a(&lst);
        else if(lst->content > lst->next->content && lst->content < lst->next->next->content)
            swap_a(&lst);
        else if(lst->content > lst->next->content && lst->next->content < lst->next->next->content)
                rotate_a(&lst);
        else if(lst->content > lst->next->content && lst->content > lst->next->next->content)
        {
            swap_a(&lst);
            reverse_rotate_a(&lst);
        }
        else if(lst->content < lst->next->content && lst->next->content > lst->next->next->content)
        {
            swap_a(&lst);
            rotate_a(&lst);
        }
    }
}

void ft_cost(t_lst *lst, t_lst *b)
{
    while(ft_lstsize_bis(b) < 2)
        push_a(&lst, &b);
    if(b->content < b->next->content)
        rotate_b(&b);
}
int ft_max(t_lst *lst)
{
    int max;
    
    max = lst->content;
    while(lst)
    {
        if(max < lst->content)
            max = lst->content;
        lst = lst->next;
    }
    printf("max = %d", max);
    return (max);
}

int ft_min(t_lst *lst)
{
    int min;
 
    min = lst->content;
    while(lst)
    {
        if(min > lst->content)
            min = lst->content;
        lst = lst->next;
    }
    return(min);
}
