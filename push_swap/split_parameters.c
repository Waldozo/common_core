/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:41:06 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/19 11:15:02 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// output
// swap sa/sb ss
// rotate ra/rb rr
// reverse rotate rra/rrb rrr
// push pa/pb
#include <stdio.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == 32 || str[i + 1] == '\n' || str[i + 1] == '\0'
				|| str[i + 1] == '\t') && (str[i] >= '0' && str[i] <= '9'))
		{
			i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}
int	len_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 32 && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	split = malloc(count_words(str) * sizeof(char *) + 1);
	if (!split)
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		split[k] = malloc(len_word(str) * sizeof(char *) + 1);
		if (!split[k])
			return (0);
		while (str[i] != 32 && str[i] != '\n' && str[i] != '\t')
			split[k][j++] = str[i++];
		while (str[i] == 32 || str[i] == '\n' || str[i] == '\t')
			i++;
		k += 1;
	}
	split[k] = NULL;
	return (split);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ac > 2)
	{
		while (av[i][j])
		{
		}
	}
}
