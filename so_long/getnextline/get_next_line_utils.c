/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:38:13 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/09 14:13:39 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dst;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len1 + 1);
	ft_strlcat(dst, s2, len1 + len2 + 1);
	free(s1);
	return (dst);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	len = ft_strlen(dst);
	i = 0;
	if (size <= len)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && len + i + 1 < size)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && (size - 1) > 0)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int n)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((char)n == str[i])
		{
			return ((char *)str + i);
		}
		i++;
	}
	if ((char)n == '\0')
	{
		return ((char *)str + i);
	}
	return (NULL);
}
