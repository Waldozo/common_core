/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:41:51 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 22:00:09 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_lst
{
	int				content;
	void			*content_bis;
	int				value;
	int				index;
	int				index_b;
	int				target;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_lst	*next;
	char			**str;
}					t_lst;

void				push_b(t_lst **a, t_lst **b, t_list **c);
void				push_a(t_lst **a, t_lst **b, t_list **c);
void				rotate_a(t_lst **a, t_list **c);
void				rotate_b(t_lst **b, t_list **c);
void				rotate_ab(t_lst **a, t_list **c);
void				reverse_rotate_a(t_lst **a, t_list **c);
void				reverse_rotate_b(t_lst **b, t_list **c);
void				reverse_rotate_ab(t_lst **a, t_list **c);
void				swap_a(t_lst **a, t_list **c);
void				swap_b(t_lst **b, t_list **c);
void				swap_ab(t_lst **a, t_list **b);
int					isnum(char *str);
long				ft_atol(char *str);
int					test(char **str);
t_lst				*process_list(char **str);
t_lst				*ft_lstlast_bis(t_lst *lst);
void				ft_lstdelone_bis(t_lst *lst, void (*del)(void *));
void				ft_lstadd_back_bis(t_lst **lst, t_lst *new);
t_lst				*ft_lstnew_bis(int content);
int					ft_lstsize_bis(t_lst *lst);
void				ft_for_three(t_lst **a, t_list **c);
void				ft_index(t_lst *a);
int					mid_value(t_lst *a);
int					ft_max(t_lst *a);
int					ft_min(t_lst *a);
void				ft_pushb(t_lst **a, t_lst **b, t_list **c);
void				ft_sort(t_lst **a, t_lst **b, t_list **c);
void				ft_push_lowest_cost(t_lst **a, t_lst **b, t_list **c,
						int lim);
t_lst				*ft_find_lowest_cost(t_lst **b, int lim);
void				ft_gettarget(t_lst **a, t_lst **b);
void				ft_calculate_cost(t_lst *a, t_lst *b);
void				ft_cost(t_lst *a, t_lst *b);
void				get_index(t_lst *a);
int					ft_find_index(t_lst *lst, int value);
int					swp_rev(t_lst *a, int element, int size);
t_lst				*ft_lstnew_ter(void *content);
void				swp_del(void *content);
void				swp_lstprint(t_list *result);
void				swp_lstprinter(t_list *lst);
void				swp_check_both(t_list *lst);
void				swp_is_both(t_list *lst, char *content, char *target,
						char *replace);
void				printf_list(t_lst **lst, t_list *c, t_lst *b);
void				free_list(t_lst *lst);
void				free_list_bis(t_list *lst);
int					swp_order(t_lst *a);
void				for_two(t_lst **a, t_list **c);
void				ft_free_tab(char **tab);
int					ft_size_tab(char **tab);
void				cleanup_memory(t_lst *a, t_list *result, char **str);
void				execute_push_swap(t_lst **a, t_list *result, t_lst *b);
char				**handle_multiple_arguments(int ac, char **argv);
#endif
