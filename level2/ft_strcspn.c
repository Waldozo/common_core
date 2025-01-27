/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:49:41 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/16 10:50:24 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
	int		i;
	size_t	count;
	int		j;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (i);
}

#include <stdio.h>

int	main(void)
{
	const char	*s;
	const char	*reject;

	s = "alut";
	reject = "t";
	printf("%zu\n", ft_strcspn(s, reject));
	printf("%zu", strcspn(s, reject));
}
