/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:04:08 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/22 12:29:55 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int ft_atoi(char *c)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while(c[i])
    {
        res = res * 10 + c[i] - '0';
        i++;
    }
    return(res);
}

void print_hex(int nbr)
{
    char c[] = "0123456789abcdef";

    if(nbr >= 16)
        print_hex(nbr / 16);
    write(1, &c[nbr %16], 1);
}
int main(int argc, char **argv)
{
    int i;
    int c;

    i = 0;
    if(argc == 2)
    {
        c = ft_atoi(argv[1]);
        print_hex(c);
    }
    write(1, "\n", 1);
}
