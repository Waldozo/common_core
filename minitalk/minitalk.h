/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walid <walid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:52:13 by walid             #+#    #+#             */
/*   Updated: 2025/01/31 14:52:16 by walid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINITALK_H
# define MINITALK_H

# include <bits/types/siginfo_t.h>
# include <errno.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include "ft_printf/ft_printf.h"
void	handler(int sig);

#endif
