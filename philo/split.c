/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:45 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/04/08 19:53:56 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	strlen_split(const char *s, char c)
{
	int	j;

	j = 0;
	while (*s != c && *s++)
		j++;
	return (j);
}

static int	count_words_split(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**result;

	i = 0;
	k = 0;
	result = malloc((count_words_split(s, c) + 1) * sizeof(char *));
	if (!result || !s)
		return (free(result), NULL);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		result[k] = malloc(strlen_split(s, c) + 1);
		if (!result[k])
			return (NULL);
		while (*s != c && *s)
			result[k][i++] = *s++;
		result[k++][i] = '\0';
		i = 0;
		while (*s == c && *s)
			s++;
	}
	return (result[k] = NULL, result);
}
