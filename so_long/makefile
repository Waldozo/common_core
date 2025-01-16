# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 10:29:13 by wlarbi-a          #+#    #+#              #
#    Updated: 2025/01/16 10:08:20 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = initialize.c
OBJ = ${SOURCE:.c=.o}
NAME = so_long.out
#CFLAGS = -Wall -Wextra -Werror -Iheaders/


%.o: %.c
	$(CC)  -I/usr/include -Iminilibx-linux -O3 -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(OBJ) minilibx-linux/libmlx_Linux.a -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

