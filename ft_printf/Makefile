# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 15:15:27 by wlarbi-a          #+#    #+#              #
#    Updated: 2024/11/23 15:16:20 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ft_putnbrbase.c ft_putstr.c ft_putchar.c ft_printf.c
OBJECT = ${SOURCE:.c=.o}
CC = gcc
CFALGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rcs $(NAME) $(OBJECT)
clean :
	rm -f $(OBJECT)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: clean fclean re all
