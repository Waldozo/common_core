# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 13:28:39 by wlarbi-a          #+#    #+#              #
#    Updated: 2025/04/19 17:04:44 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c split.c utils.c parsing.c initialize.c check_arguments.c states.c
OBJ = ${SRCS:.c=.o}
CC = cc
NAME = philo
FLAGS = -Wall -Wextra -Werror -pthread -g3

all : $(NAME)

%.o: %.cc
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -g3 -o $@

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re