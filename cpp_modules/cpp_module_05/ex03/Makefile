NAME := intern
CC := c++
COMPILE_FLAGS := -std=c++98 -Wall -Wextra -Werror
SRC := 	main.cpp					Bureaucrat.cpp			AForm.cpp \
		ShrubberyCreationForm.cpp	RobotomyRequestForm.cpp	PresidentialPardonForm.cpp \
		Intern.cpp
OBJ := $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(COMPILE_FLAGS) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(COMPILE_FLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
