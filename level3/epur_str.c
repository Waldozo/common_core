/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:33:18 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/22 10:52:33 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
int ft_strlen(char *c)
{
    int i;

    i = 0;
    while(c[i] != '\0')
        i++;
    return(i);
}
int main(int argc, char **argv)
{
    int i;
    int j;

    j = ft_strlen(argv[1]) - 1;
    i = 0;
    if(argc == 2)
    {
        while(argv[1][i] == 32 || argv[1][i] == '\t')
            i++;
        while(argv[1][j] == 32 || argv[1][j] == '\t')
            j--;
        while(argv[1][i])
        {
            while(argv[1][i] != 32 && argv[1][i] != '\t' && argv[1][i] && i <=j)
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            if((argv[1][i] == 32 || argv[1][i] == '\t') && i <= j)
            {
                write(1, " ", 1);
                i++;
            }
            while(argv[1][i] == 32 || argv[1][i] == '\t')
                i++;
        }
    }
    write(1, "\n", 1);
}