/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:29:28 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/24 12:37:00 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_FUNCTIONS_H
# define TOOL_FUNCTIONS_H

# include "../interpreter/interpreter.h"
# include "../state.h"

int		count_strings(char **commands);
int		if_exist_equal_sign(char *string);
char	*expand_variables(char *string, t_state *state);
int		exist_envv_variable(char *string, int with_null, t_state *state);
char	*get_var_from_envv(char *string, t_state *state);
void	safe_free_string(char **string);
void	safe_free_multiple_strings(char ***splitted);
int		count_args_in_node(t_node *node);
void	error_exit(const char *string);
void	print_envv(int which, t_state *state);
int		if_not_all_valid_printable(char *string, int equal_sign);
char	**command_from_node(t_node *node);
void	print_input_file_error(char *file);
void	print_output_file_error(char *file);
void	close_all_pipes(t_state *state);
void	clean_after_execution(t_state *state);
char	*find_last_argument_from_node(t_node *node);
void	replace_envv(char *string, char *search, int with_nul, t_state *state);
void	child_check_errors(char **command);
void	ini_execute_program(int *fd_input, int *fd_output, t_state *state);
void	if_there_are_pipes(int *fd_input, int *fd_output, t_state *state);
void	if_there_is_input_output(int *fd_input, int *fd_output, t_state *state);
void	wait_pid_when_pipes(t_state *state, int *status);
void	print_numeric_argument_required_exit(t_node *node, t_state *state);
void	dup_and_close(t_state *state, int fd_input, int fd_output);
void	print_cd_error(char *string);
void	remove_variable_from_envv(char *string, char **envv, int with_null);
char	*variable_up_to_equal_sign(char *string);
void	initialize_handle_exit_return_value_values(int *index,
			long long int *number, int *is_negative);

#endif
