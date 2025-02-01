# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 14:05:28 by walid             #+#    #+#              #
#    Updated: 2025/02/01 13:58:16 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c ft_atoi.c ft_isdigit.o
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF_PATH = ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a

all: server client


server: $(OBJECTS) $(PRINTF)
#	$(CC) -o $@ $<
	$(CC) $(CFALGS) server.o ft_atoi.o ft_isdigit.o -o server $(PRINTF)

client: $(OBJECTS) $(PRINTF)
#	$(CC) -o $@ $<
	$(CC) $(CFLAGS) client.o ft_atoi.o ft_isdigit.o -o client $(PRINTF)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF) :
	make -C $(PRINTF_PATH) all

clean:
	make -C ft_printf clean
	rm -f $(OBJECTS)

fclean: clean
	
	rm -f server client ft_printf/libftprintf.a
	

re: fclean all

.PHONY: all clean fclean re
