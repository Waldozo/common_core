/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:17 by wlarbi-a          #+#    #+#             */
/*   Updated: 2024/12/16 13:36:49 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	t;

	j = strlen(str) - 1;
	i = 0;
	if (!str)
		return (0);
	while (i < j)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
		i++;
		j--;
	}
	return (str);
}
#include <stdio.h>

int main()
{
    // Exemple avec une chaîne de caractères
    char str[] = "Bonjour le monde";

    printf("Avant inversion: %s\n", str);
    ft_strrev(str);  // Inverser la chaîne
    printf("Après inversion: %s\n", str);

    return 0;
}
