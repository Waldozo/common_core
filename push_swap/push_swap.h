/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:41:51 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/26 16:56:12 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdio.h>

void				ft_putnbr(int nb);

typedef struct s_lst
{
	int				content;
	int				value;
	int				index;
	int				target;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_lst	*next;
	char			**str;
}					t_lst;

void				push_b(t_lst **a, t_lst **b);
void				push_a(t_lst **a, t_lst **b);
void				rotate_a(t_lst **a);
void				rotate_b(t_lst **b);
void				rotate_ab(t_lst **a, t_lst **b);
void				reverse_rotate_a(t_lst **a);
void				reverse_rotate_b(t_lst **b);
void				reverse_rotate_ab(t_lst **a, t_lst **b);
void				swap_a(t_lst **a);
void				swap_b(t_lst **b);
void				swap_ab(t_lst **a, t_lst **b);
int					isnum(char *str);
long				ft_atol(char *str);
int					test(char **str);
t_lst				*process_list(char **str);
t_lst				*ft_lstlast_bis(t_lst *lst);
void				ft_lstadd_back_bis(t_lst **lst, t_lst *new);
t_lst				*ft_lstnew_bis(int content);
int					ft_lstsize_bis(t_lst *lst);
// void				ft_for_two(t_lst *lst);
void				ft_for_three(t_lst *a);
void				ft_index(t_lst *a);
int					ft_max(t_lst *a);
int					ft_min(t_lst *a);
void				ft_pushb(t_lst **a, t_lst **b, int size);
void				ft_sort(t_lst **a, t_lst **b);
void				ft_push_lowest_cost(t_lst **a, t_lst **b);
t_lst				*ft_find_lowest_cost(t_lst **b);
void				ft_gettarget(t_lst **a, t_lst **b);
void				ft_calculate_cost(t_lst **a, t_lst **b);
void				ft_cost(t_lst *a, t_lst *b);
#endif
