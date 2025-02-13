/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:29:23 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/01/22 13:49:53 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
    int nbr1;
    int nbr2;
    int tmp;
    
    if(argc == 3)
    {
        if((nbr1 = atoi(argv[1])) > 0 && (nbr2 = atoi(argv[2])) > 0)
        {
            while(nbr2 != 0)
            {
                tmp = nbr2;
                nbr2 = nbr1 % nbr2;
                nbr1 = tmp;
            }
            printf("%d", nbr1);
        }
    }
    printf("\n");
}