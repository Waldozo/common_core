/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:30:49 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/23 13:23:25 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
void printf_list(t_lst *lst);

int	main(int ac, char **argv)
{
	int		i;
	char	**str;
	t_lst	*lst;

	i = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		str = ft_split(argv[1], ' ');
		test(str);
	}
	else
	{
		str = malloc(sizeof(char *) * ac);
		while (i < ac - 1)
		{
			str[i] = argv[i + 1];
			i++;
		}
		test(str);
	}
	lst = process_list(str);
	printf_list(lst);
	return (0);
}
