SERVER_NAME = server
SERVER_COMPILE_FLAGS = -Ofast -Wall -Wextra -Werror
SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_NAME = client
CLIENT_COMPILE_FLAGS = -Ofast -Wall -Wextra -Werror
CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

.PHONY: all clean fclean re

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ) libft/libft.a
	cc -o $(SERVER_NAME) -Llibft -lft $(SERVER_COMPILE_FLAGS) $(SERVER_OBJ)

$(SERVER_OBJ): $(SERVER_SRC)
	cc -c -I libft $(SERVER_COMPILE_FLAGS) $(SERVER_SRC)

$(CLIENT_NAME): $(CLIENT_OBJ) libft/libft.a
	cc -o $(CLIENT_NAME) -Llibft -lft $(CLIENT_COMPILE_FLAGS) $(CLIENT_OBJ)

$(CLIENT_OBJ): $(CLIENT_SRC)
	cc -c -I libft $(CLIENT_COMPILE_FLAGS) $(CLIENT_SRC)

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all
