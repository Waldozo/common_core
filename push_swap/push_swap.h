/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:41:51 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/25 17:46:02 by wlarbi-a         ###   ########.fr       */
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
void				ft_turc(t_lst *lst, t_lst **b);
void				ft_for_two(t_lst *lst);
void				ft_for_three(t_lst *lst);
void				ft_index(t_lst *lst);
int					ft_max(t_lst *lst);
int					ft_min(t_lst *lst);
#endif
