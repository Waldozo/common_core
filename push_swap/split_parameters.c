/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:30:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/04 20:00:27 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


// int	main(int ac, char **argv)
// {
// 	int		i;
// 	char	**str;
// 	t_lst	*a;
// 	t_list *result;

// 	i = 0;
// 	if (ac < 2)
// 		return (0);
// 	if (ac == 2)
// 	{
// 		str = ft_split(argv[1], ' ');
// 		test(str);
// 	}
// 	else
// 	{
// 		str = malloc(sizeof(char *) * ac);
// 		while (i < ac - 1)
// 		{
// 			str[i] = argv[i + 1];
// 			i++;
// 		}
// 		test(str);
// 	}
// 	result = ft_lstnew(ft_strdup(""));
// 	a = process_list(str);
// 	// t_lst *curr = a; 
// 	// for (int i =0; i < ft_lstsize_bis(a); i++)
// 	// {
// 	// 	printf("%d\n", curr->content);
// 	// 	curr = curr->next;
// 	// }
// 	// // printf("------------------------------\n");
// 	// t_lst *curr1 = a; 
// 	// for (int i =0; i < ft_lstsize_bis(a); i++)
// 	// {
// 	// 	printf("%d\n", curr1->content);
// 	// 	curr1 = curr1->next;
// 	// }
// 	printf_list(a, result);
// 	free_list(a);
// 	swp_lstprint(result);
// 	free_list_bis(result);
// 	free(str);
// 	return (0);
// }

int	main(int ac, char **argv)
{
    int		i;
    char	**str;
    t_lst	*a;
    t_list	*result;

    if (ac < 2)
        return (0);
    if (ac == 2)
        str = ft_split(argv[1], ' ');
    else
    {
        str = malloc(sizeof(char *) * ac);
        if (!str)
            return (1);
        i = 0;
        while (i < ac - 1)
        {
            str[i] = ft_strdup(argv[i + 1]);
            if (!str[i])
            {
                while (i >= 0)
                   { free(str[i]); i--;}
                free(str);
                return (1);
            }
            i++;
        }
        str[i] = NULL;
    }
    a = process_list(str);
    result = ft_lstnew(ft_strdup(""));
	printf_list(a, result);
    // t_lst *curr = a; 
    // for (int i =0; i < ft_lstsize_bis(a); i++)
    // {
    // 	printf("%d\n", curr->content);
    // 	curr = curr->next;
    // }
    swp_lstprint(result);
    // t_lst *curr1 = a;
    // for (int i =0; i < ft_lstsize_bis(a); i++)
    // {
    // 	printf("%d\n", curr1->content);
    // 	curr1 = curr1->next;
	// }
    free_list(a);
    free_list_bis(result);
    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    return (0);
}

