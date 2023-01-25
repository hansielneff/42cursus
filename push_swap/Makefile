NAME = push_swap
COMPILE_FLAGS = -Wall -Wextra -Werror
SRC = push_swap.c stack.c instructions.c solutions.c short_sort.c radix_sort.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	cc -o $(NAME) -Llibft -lft $(COMPILE_FLAGS) $(OBJ)

$(OBJ): $(SRC)
	cc -c -I libft $(COMPILE_FLAGS) $(SRC)

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
