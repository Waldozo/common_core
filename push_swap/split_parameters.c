/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:30:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/06 19:03:28 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// int	main(int ac, char **argv)
// {
//     int		i;
//     char	**str;
//     t_lst	*a;
//     t_list	*result;
//     t_lst    *b;

//     b = NULL;
//     str = NULL;

//     if (ac < 2)
//         return (0);
//     if (ac == 2)
//         str = ft_split(argv[1], ' ');
//     else
//     {
//         str = malloc(sizeof(char *) * ac);
//         if (!str)
//             return (1);
//         i = 0;
//         while (i < ac - 1)
//         {
//             str[i] = ft_strdup(argv[i + 1]);
//             if (!str[i])
//             {
//                 while (i >= 0)
//                    { free(str[i]); i--;}
//                 free(str);
//                 return (1);
//             }
//             i++;
//         }
//         str[i] = NULL;
//     }
//     if(test(str) == 0)
//     {
//         return (0);
//     }
//     a = process_list(str);
//     result = ft_lstnew(ft_strdup(""));
//     printf_list(&a, result, b);
//     swp_lstprint(result);
//     free_list(a);
//     free_list_bis(result);
//     i = 0;
//     while (str[i])
//         free(str[i++]);
//     free(str);
//     return (0);
// }


char	**handle_multiple_arguments(int ac, char **argv)
{
    char	**str;
    int		i;

    str = malloc(sizeof(char *) * ac);
    if (!str)
        return (NULL);
    i = 0;
    while (i < ac - 1)
    {
        str[i] = ft_strdup(argv[i + 1]);
        if (!str[i])
        {
            while (i >= 0)
                free(str[i--]);
            free(str);
            return (NULL);
        }
        i++;
    }
    str[i] = NULL;
    return (str);
}

void	execute_push_swap(t_lst **a, t_list *result, t_lst *b)
{
	printf_list(a, result, b);
	swp_lstprint(result);
}

void	cleanup_memory(t_lst *a, t_list *result, char **str)
{
	int	i;

	free_list(a);
	free_list_bis(result);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	main(int ac, char **argv)
{
	char **str;
	t_lst *a;
	t_list *result;
    t_lst *b;
    b = NULL;

    if (ac < 2)
        return (0);
    if (ac == 2)
    {
        str = ft_split(argv[1], ' ');
    }
    else
    {
        str = handle_multiple_arguments(ac, argv);
    }
    if (test(str) == 0)
    {
        return (0);
    }
	a = process_list(str);
	result = ft_lstnew(ft_strdup(""));
	execute_push_swap(&a, result, b);
	cleanup_memory(a, result, str);
	return (0);
}
