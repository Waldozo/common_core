/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:30:16 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/09 11:39:01 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
int count_words(char *str)
{
	int i;
	int c;
	i = 0;
	c = 0;

	while(str[i] != '\0')
	{
		if((str[i + 1] == ' ' || str[i + 1] == '\t' || str[i+1] == '\0') && str[i] != ' ' &&
				str[i] != '\t')
		{
			c++;
			i++;
		}
		else
			i++;
	}
	return(c);

}
int main(int argc, char **argv)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	if(argc == 2)
	{
		while((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i] != '\0')
			i++;
		while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
		{
			str[j] = argv[1][i];
			i++;
			j++;
		}
		while((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i] != '\0')
			i++;
		str[j] = '\0';
		while(argv[1][i] != '\0')
		{
			if(argv[1][i] == ' ')
				write(1, " ", 1);
			while(argv[1][i] == ' ')
				i++;
			write(1, &argv[1][i], 1);
			i++;
		}
		j = 0;
		if(count_words(argv[1]) > 1)
			write(1, " ", 1);
		while(str[j] != '\0')
		{
			write(1, &str[j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}
