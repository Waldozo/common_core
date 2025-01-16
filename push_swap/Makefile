# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 13:40:34 by wlarbi-a          #+#    #+#              #
#    Updated: 2024/12/18 09:16:49 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = 
OBJECT = ${SOURCE:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJECT)
        ar rcs $(NAME) $(OBJECT)
%.o:%.c ft_printf.h
        $(CC) $(CFLAGS)  -c $< -o $@
clean :
        rm -f $(OBJECT)
fclean : clean
        rm -f $(NAME)
re : fclean all

.PHONY: clean fclean re all
