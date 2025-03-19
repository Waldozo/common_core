# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 14:05:28 by walid             #+#    #+#              #
#    Updated: 2025/03/19 12:30:27 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c ft_atoi.c ft_isdigit.c
BONUS = server_bonus.c client_bonus.c ft_atoi.c ft_isdigit.c
OBJECTS_BONUS = $(BONUS:.c=.o)
OBJECTS = $(SOURCES:.c=.o)
NAME = ${SERVER} ${CLIENT}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF_PATH = ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a

all: server client

bonus: server_bonus client_bonus

server: $(OBJECTS) $(PRINTF)
	$(CC) $(CFALGS) server.o ft_atoi.o ft_isdigit.o -o server $(PRINTF)

client: $(OBJECTS) $(PRINTF)
	$(CC) $(CFLAGS) client.o ft_atoi.o ft_isdigit.o -o client $(PRINTF)
	
server_bonus: $(OBJECTS_BONUS) $(PRINTF)
	$(CC) $(CFLAGS) server_bonus.o ft_atoi.o ft_isdigit.o -o server_bonus $(PRINTF)

client_bonus: $(OBJECTS_BONUS) $(PRINTF)
	$(CC) $(CFLAGS) client_bonus.o ft_atoi.o ft_isdigit.o -o client_bonus $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF) :
	make -C $(PRINTF_PATH) all

clean:
	make -C ft_printf clean
	rm -f $(OBJECTS_BONUS)
	rm -f $(OBJECTS)

fclean: clean
	rm -f server_bonus client_bonus $(OBJECTS_BONUS)
	rm -f server client ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
