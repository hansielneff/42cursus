NAME = libftprintf.a
COMPILE_FLAGS = -Wall -Wextra -Werror
INCLUDE = libft
SRC = ft_printf.c ft_arg_util.c ft_parser.c ft_writer.c

.PHONY: all libft clean fclean re

all: $(NAME)

$(NAME): $(SRC:.c=.o) libft
	ar rus $(NAME) $(SRC:.c=.o)

$(SRC:.c=.o): $(SRC)
	cc -c -I $(INCLUDE) $(COMPILE_FLAGS) $(SRC)

libft:
	make -C libft
	make -C libft bonus
	cp libft/libft.a $(NAME)

clean:
	make -C libft clean
	rm -f $(SRC:.c=.o) $(BONUS:.c=.o)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
