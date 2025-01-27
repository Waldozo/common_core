/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:53:26 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/22 11:20:16 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
int ft_atoi(char *c)
{   
    int res;
    int i;
    
    i = 0;
    res = 0;
    while(c[i])
    {
        res = res * 10 + c[i] - '0';
        i++;
    }
    return(res);
    
}
int ft_is_prime(int c)
{
    int i;

    i = 2;
    if(c <= 1)
        return(0);
    while(i * i <= c)
    {
        if(c % i == 0)
            return(0);
        i++;
    }
    return(1);
    
}

void ft_putnbr(int nbr)
{
    char c;
    
    if(nbr >= 10)
        ft_putnbr(nbr / 10);
    c = nbr % 10 + '0';
    write(1, &c, 1); 
}

int main(int argc, char **argv)
{
    int c;
    int res;


    if(argc == 2)
    {
        c = ft_atoi(argv[1]);
        res = 0;
        while(c > 0)
        {
            if(ft_is_prime(c))
                res += c; 
            c--;
        }
        ft_putnbr(res);
    }
    if (argc != 2)
        ft_putnbr(0);
    write(1, "\n", 1);
    return(0);
}