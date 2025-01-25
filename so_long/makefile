# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 10:29:13 by wlarbi-a          #+#    #+#              #
#    Updated: 2025/01/18 14:00:29 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = initialize.c ./getnextline/get_next_line_utils.c ./getnextline/get_next_line.c 
OBJ = ${SOURCE:.c=.o}
NAME = so_long.out
CFLAGS = -Wall -Wextra -Werror -Iheaders/


all : $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -I/getnextline -I/usr/include -Iminilibx-linux -O3 -c $< -o $@
$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) minilibx-linux/libmlx_Linux.a -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME) ./libft/libft.a
clean :
	make -C libft fclean
	rm -f $(OBJ)
fclean : clean 
	make -C libft fclean
	rm -f $(NAME)