/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:30:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/04 23:18:58 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>



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
    if(test(str) == 0)
    {
        return (0);
    }
    a = process_list(str);
    result = ft_lstnew(ft_strdup(""));
    printf_list(&a, result);
    swp_lstprint(result);
    free_list(a);
    free_list_bis(result);
    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    return (0);
}
