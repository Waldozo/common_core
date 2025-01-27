/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:33:45 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/07/14 17:51:46 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_str_rev(char *str)
{
	int	i;
	int	size;
	int	tmp;

	size = ft_str_len(str);
	tmp = 0;
	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = tmp;
		i++;
	}
	return (str);
}
#include<stdio.h>
int	main(void)
{
	char	str[] = "salut";

	printf("%s", ft_str_rev(str));

}
