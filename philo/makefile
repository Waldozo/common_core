# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 13:28:39 by wlarbi-a          #+#    #+#              #
#    Updated: 2025/05/02 16:35:56 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c utils.c parsing.c initialize.c check_arguments.c states.c eating.c routine.c free.c
OBJ = ${SRCS:.c=.o}
CC = cc
NAME = philo
FLAGS = -Wall -Wextra -Werror -pthread 

all : $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -o $@

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re