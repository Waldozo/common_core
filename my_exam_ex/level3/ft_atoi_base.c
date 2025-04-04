/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:20:56 by wlarbi-a          #+#    #+#             */
/*   Updated: 2025/03/24 15:51:18 by wlarbi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(const char *str, int str_base)
{
    int sign = 1;
    int res = 0;
    int i = 0;
    int c = 0;
    
    if(str[0] == '-')
    {
        sign = -1;
        i++;
    }
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
            c = str[i] + '0';
        else if(str[i] >= 'a' && str[i] <= 'f')
            c = str[i] - 'a' + 10;
        else if(str[i] >= 'A' && str[i] <= 'F')
            c = str[i] - 'A' + 10;
        res = res * str_base + c;
        i++;
    }
    return(res *sign);
}
#include <stdio.h>

int main(void)
{
    int str_base;
    const char *str;

    str = "10";
    str_base = 16;
    printf("%d", ft_atoi_base(str, str_base));
    
    
}