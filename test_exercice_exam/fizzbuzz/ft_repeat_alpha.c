/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:09:44 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/07/11 11:47:48 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
void	ft_repeat_alpha(char	*str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0' && str[i] >= 97 && str[i] <= 122)
	{
		j = str[i];
		while (j - 97 >= 0)
		{
			write(1, &str[i], 1);
			j--;
		}
		i++;
	}
}

int	main(void)
{
	char	*str = "abcdefghijklmnopqrstuvwxyz";

	ft_repeat_alpha(str);
}
