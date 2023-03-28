NAME = philo
COMPILE_FLAGS = -Wall -Wextra -Werror -O3
SRC = main.c arguments.c logging.c philosophers.c philo_actions.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(COMPILE_FLAGS) $(OBJ)

$(OBJ): $(SRC)
	cc -c $(COMPILE_FLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
