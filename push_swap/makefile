# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 08:30:31 by wlarbi-a          #+#    #+#              #
#    Updated: 2025/04/06 22:00:03 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = split_parameters.c parsing.c utils.c utils_2.c list.c rotate.c rrotate.c push.c  swap.c algorythm.c cost.c free.c instructions.c
OBJECT = ${SOURCE:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@
$(NAME) : $(OBJECT)
	@make -C libft bonus --no-print-directory
	@make -C ft_printf --no-print-directory
	@$(CC) $(OBJECT) -o $(NAME) ./libft/libft.a ./ft_printf/libftprintf.a
	@echo push_swap compiled
clean :
	@make -C libft clean --no-print-directory
	@make -C ft_printf clean --no-print-directory
	@rm -f $(OBJECT)
fclean : clean
	@make -C libft fclean --no-print-directory
	@make -C ft_printf fclean --no-print-directory
	@rm -f $(NAME)
	@echo everything is cleaned
re : fclean all

.PHONY: clean fclean re all
