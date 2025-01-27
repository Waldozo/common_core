/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:03:59 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/16 11:33:37 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				return ((char *)s1 + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s1;
	const char	*s2;

	s1 = "salut";
	s2 = "a";
	printf("%s\n", ft_strpbrk(s1, s2));
	printf("%s", strpbrk(s1, s2));
}
