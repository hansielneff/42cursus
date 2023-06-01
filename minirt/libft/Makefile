NAME = libft.a
COMPILE_FLAGS = -Wall -Wextra -Werror
CORE = \
	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c		ft_isascii.c \
	ft_isprint.c	ft_strlen.c		ft_memset.c			ft_bzero.c \
	ft_memcpy.c		ft_memmove.c	ft_strlcpy.c		ft_strlcat.c \
	ft_toupper.c	ft_tolower.c	ft_strchr.c			ft_strrchr.c \
	ft_strncmp.c	ft_memchr.c		ft_memcmp.c			ft_strnstr.c \
	ft_atoi.c		ft_calloc.c		ft_strdup.c			ft_substr.c \
	ft_strjoin.c	ft_strtrim.c	ft_split.c			ft_itoa.c \
	ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c		ft_putstr_fd.c \
	ft_putendl_fd.c	ft_putnbr_fd.c
BONUS = \
	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	ft_lstsize_bonus.c	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
EXTRA = \
	ft_min.c			ft_max.c			ft_digitsl.c	ft_digitsul.c \
	ft_based_lltoa.c	ft_based_ulltoa.c	ft_utoa.c		ft_count.c \
	ft_chrtostr.c		ft_strpad.c			ft_lstdellast.c ft_strsubst.c
GNL = \
	get_next_line/get_next_line.c
PRINTF = \
	ft_printf/ft_printf.c ft_printf/ft_arg_util.c	ft_printf/ft_parser.c	ft_printf/ft_writer.c
SRC = $(CORE) $(BONUS) $(EXTRA) $(GNL) $(PRINTF)
OBJ = $(SRC:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(notdir $(OBJ))

$(OBJ): $(SRC)
	@cc -c $(COMPILE_FLAGS) $(SRC)
	@ar rcs $(NAME) $(notdir $(OBJ))

clean:
	@rm -f $(notdir $(OBJ))

fclean: clean
	rm -f $(NAME)

re: fclean all
