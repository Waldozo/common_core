# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: walid <walid@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 14:05:28 by walid             #+#    #+#              #
#    Updated: 2025/01/31 14:57:36 by walid            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SOURCES = server.c client.c ft_atoi.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

%.o: %.c
	$(CC) -c $(CFLAGS)

server: server.o
	make -C ft_printf
	$(CC) -o $@ $<  
	$(CC) $(OBJECTS) server ./ft_printf/libftprintf.a

client: client.o
	make -C ft_printf
	$(CC) -o $@ $<  
	$(CC) $(OBJECTS) client ./ft_printf/libftprintf.a
	
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f server client ft_printf/libftprintf.a
	

re: fclean all

.PHONY: all clean fclean re
