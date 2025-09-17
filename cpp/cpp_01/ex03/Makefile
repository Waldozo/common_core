NAME = Human

SOURCE = HumanA.cpp  HumanB.cpp  Weapon.cpp  main.cpp

OBJECT = $(SOURCE:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECT)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECT)
	
fclean : clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re all