/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:43:12 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/11/24 10:43:39 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *str, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			n += 1;
		while (str[i] != c && str[i])
			i++;
	}
	return (n);
}

static size_t	ft_len_w(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **split, size_t j)
{
	if (!split[j])
	{
		while (j > 0)
		{
			free(split[j]);
			j--;
		}
		free(split);
	}
}

static char	**ft_verif(char const *s, char c, char **split)
{
	size_t	j;
	size_t	i;
	size_t	len_w;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		len_w = ft_len_w(s + i, c);
		split[j] = ft_substr(s, i, len_w);
		if (!split[j + 1])
		{
			ft_free(split, j + 1);
			return (NULL);
		}
		i += len_w;
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!ft_verif(s, c, split))
		return (NULL);
	return (split);
}
