/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:38:54 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/02/06 12:49:15 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	count_word(char *c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (c[i] != '\0')
	{
		if ((c[i + 1] == 32 || c[i + 1] == '\0' || c[i + 1] == '\t' || c[i
				+ 1] == '\n') && ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A'
					&& c[i] <= 'Z') || (c[i] >= '0' && c[i] <= '9')))
		{
			count++;
			i++;
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
	while (str[i] != '\0' && str[i] != 32 && str[i] != '\n' && str[i] != '\t')
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	// if (count_word(str) == 0)
	// 	return(NULL);
	split = malloc(1000000);
	if (!split)
		return (0);
	while(str[i] == 32 && '\t' && '\n')
		i++;
	while (str[i] != '\0')
	{
		j = 0;
		split[k] = malloc(10000000);
		if (!split[k])
			return (0);
		while (str[i] != 32 && str[i] != '\t' && str[i] != '\n')
			split[k][j++] = str[i++];
		split[k][j++] = '\0';
		while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
			i++;
		k += 1;
	}
	split[k] = NULL;
	return (split);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
	char	**res;
	int		i;

	str = "    ";
	res = ft_split(str);
	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	if (res[i] == NULL)
		printf("%p", NULL);
	free(res);
	return (0);
}
