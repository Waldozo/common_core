# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlarbi-a <wlarbi-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 10:29:13 by wlarbi-a          #+#    #+#              #
#    Updated: 2025/01/30 14:59:40 by wlarbi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = initialize.c init_image.c map_error.c key_press.c ./getnextline/get_next_line_utils.c ./getnextline/get_next_line.c 
OBJ = ${SOURCE:.c=.o}
NAME = so_long
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)
	
%.o: %.c
	@$(CC) $(CFLAGS) -I/getnextline -I/usr/include -Iminilibx-linux -O3 -c $< -o $@
$(NAME): $(OBJ)
	@make -C libft --no-print-directory
	@make -C ft_printf --no-print-directory
	@$(CC) $(OBJ) minilibx-linux/libmlx_Linux.a -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME) ./libft/libft.a ./ft_printf/libftprintf.a
	@echo so_long compiled
clean :
	@make -C libft clean --no-print-directory
	@make -C ft_printf fclean --no-print-directory
	@rm -f $(OBJ) $(NAME)
	@echo so_long  /ft_printf /libft deleted
fclean : clean 
	@make -C libft fclean --no-print-directory
	@make -C ft_printf fclean --no-print-directory
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all