/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:41:55 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/14 14:00:02 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*rev_print(char *str)
{
	int	i;

	while (str[i] != '\0')
	{
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (str);
}

int	main(void)
{
	char	*str;

	str = "Hello    wolrd!";
	rev_print(str);
}
