NAME = 

SOURCE = 

OBJECT = $(SOURCE:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECT)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJECT)
	
fclean : clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re all
