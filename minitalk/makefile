SERVER = server
CLIENT = client
SOURCE_SERVER = server.c
SOURCE_CLIENT = client.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_SERVER = $(SOURCE_SERVER:.c=.o)
OBJ_CLIENT = $(SOURCE_CLIENT:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_SERVER)
	ar -rcs $(OBJ_SERVER)
$(CLIENT) : $(OBJ_CLIENT)
	ar -rcs $(OBJ_CLIENT)
clean :
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
fclean : clean
	rm -f $(CLIENT) $(SERVER)
re : fclean all

.PHONY: clean fclean re all
