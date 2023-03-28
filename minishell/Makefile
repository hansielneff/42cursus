NAME := minishell
COMPILE_FLAGS := -Wall -Wextra -Werror
SRC := minishell.c \
	lexer/lexer.c \
		lexer/tokens/token.c lexer/tokens/invalid_token.c \
		lexer/tokens/whitespace_token.c lexer/tokens/expansion_token.c \
		lexer/tokens/raw_str_token.c \
		lexer/tokens/expand_str_token.c lexer/tokens/word_token.c \
		lexer/tokens/pipe_token.c lexer/tokens/redirect_in_1_token.c \
		lexer/tokens/redirect_in_2_token.c lexer/tokens/redirect_out_1_token.c \
		lexer/tokens/redirect_out_2_token.c \
	parser/parser.c \
		parser/ast/ast.c \
			parser/ast/nodes/expression_node.c parser/ast/nodes/command_node.c \
			parser/ast/nodes/term_node.c parser/ast/nodes/expansion_node.c \
			parser/ast/nodes/word_node.c parser/ast/nodes/raw_str_node.c \
			parser/ast/nodes/expand_str_node.c parser/ast/nodes/pipe_node.c \
			parser/ast/nodes/redirect_node.c \
	interpreter/interpreter.c \
		interpreter/actions/invalid_action.c interpreter/actions/command_action.c \
		interpreter/builtins/builtin_echo.c interpreter/builtins/builtin_pwd.c \
		interpreter/builtins/builtin_cd.c interpreter/builtins/builtin_exit.c \
		interpreter/builtins/builtin_env.c interpreter/builtins/builtin_unset.c \
		interpreter/builtins/builtin_export.c interpreter/actions/pipe_action.c \
		interpreter/actions/redirect_action.c interpreter/builtins/builtin_export2.c \
		interpreter/builtins/builtin_exit2.c \
	initialization/initialize.c initialization/enable_raw_mode.c \
		initialization/disable_raw_mode.c initialization/set_signal_handlers.c \
		initialization/initialize_envv.c initialization/clean_state_between_commands.c \
	tool_functions/count_strings.c \
		tool_functions/if_exist_equal_sign.c tool_functions/expand_variables.c \
		tool_functions/exist_envv_variable.c tool_functions/get_var_from_envv.c \
		tool_functions/safe_free_multiple_strings.c tool_functions/safe_free_string.c \
		tool_functions/count_args_in_node.c tool_functions/error_exit.c \
		tool_functions/print_envv.c tool_functions/if_not_all_valid_printable.c \
		tool_functions/command_from_node.c tool_functions/print_input_file_error.c \
		tool_functions/print_output_file_error.c tool_functions/clean_after_execution.c \
		tool_functions/close_all_pipes.c tool_functions/find_last_argument_from_node.c \
		tool_functions/replace_envv.c tool_functions/child_check_errors.c \
		tool_functions/ini_execute_program.c tool_functions/if_there_are_pipes.c \
		tool_functions/if_there_is_input_output.c tool_functions/wait_pid_when_pipes.c \
		tool_functions/print_numeric_argument_required_exit.c tool_functions/dup_and_close.c \
		tool_functions/print_cd_error.c tool_functions/remove_variable_from_envv.c \
		tool_functions/variable_up_to_equal_sign.c \
		tool_functions/initialize_handle_exit_return_value_values.c \
	signals/not_signal_control_d.c \
		signals/signal_control_c.c signals/signal_do_nothing.c \
		signals/signal_control_c_heredoc.c \
	execution/execute_program.c execution/child_execution.c \
		execution/execute_heredoc.c
		
OBJ := \
minishell.o  \
lexer.o  \
token.o \
invalid_token.o  \
whitespace_token.o \
expansion_token.o  \
raw_str_token.o  \
expand_str_token.o \
word_token.o  \
pipe_token.o \
redirect_in_1_token.o  \
redirect_in_2_token.o \
redirect_out_1_token.o  \
redirect_out_2_token.o  \
parser.o  \
ast.o  \
expression_node.o \
command_node.o  \
term_node.o \
expansion_node.o  \
word_node.o \
raw_str_node.o  \
expand_str_node.o \
pipe_node.o  \
redirect_node.o  \
interpreter.o  \
invalid_action.o \
command_action.o  \
builtin_echo.o \
builtin_pwd.o  \
builtin_cd.o \
builtin_exit.o  \
builtin_env.o \
builtin_unset.o  \
builtin_export.o \
pipe_action.o  \
redirect_action.o \
builtin_export2.o  \
builtin_exit2.o  \
initialize.o \
enable_raw_mode.o  \
disable_raw_mode.o \
set_signal_handlers.o  \
initialize_envv.o \
clean_state_between_commands.o  \
count_strings.o  \
if_exist_equal_sign.o \
expand_variables.o  \
exist_envv_variable.o \
get_var_from_envv.o  \
safe_free_multiple_strings.o \
safe_free_string.o  \
count_args_in_node.o \
error_exit.o  \
print_envv.o \
if_not_all_valid_printable.o  \
command_from_node.o \
print_input_file_error.o  \
print_output_file_error.o \
clean_after_execution.o  \
close_all_pipes.o \
find_last_argument_from_node.o  \
replace_envv.o \
child_check_errors.o  \
ini_execute_program.o \
if_there_are_pipes.o  \
if_there_is_input_output.o \
wait_pid_when_pipes.o  \
print_numeric_argument_required_exit.o \
dup_and_close.o  \
print_cd_error.o \
remove_variable_from_envv.o  \
variable_up_to_equal_sign.o  \
initialize_handle_exit_return_value_values.o  \
not_signal_control_d.o  \
signal_control_c.o \
signal_do_nothing.o  \
signal_control_c_heredoc.o  \
execute_program.o \
child_execution.o  \
execute_heredoc.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	cc -o $(NAME) -Llibft -lft -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include $(COMPILE_FLAGS) $(OBJ)

$(OBJ): $(SRC)
	cc -c -I libft -I ~/.brew/opt/readline/include $(COMPILE_FLAGS) $(SRC)

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
