/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:21:25 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/24 12:35:44 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../../interpreter/interpreter.h"
#include "../../libft/libft.h"
#include "../../tool_functions/tool_functions.h"
#include "../../minishell.h"
#include "../../initialization/initialization.h"
#include "unistd.h"

int	handle_loop_exit_return_value(t_node *node,
	t_state *state, int *index, char **place)
{
	while ((*place)[*index] && (*place)[*index] <= 32)
		++(*index);
	if ((*place)[*index] != '\0')
	{
		print_numeric_argument_required_exit(node, state);
		return (1);
	}
	return (0);
}

static void	handle_exit_return_value_with_pipes(t_node *node, t_state *state)
{
	int				index;
	long long int	number;
	int				is_negative;
	char			*place;

	initialize_handle_exit_return_value_values(&index, &number, &is_negative);
	if (node->args->token->value[0] == '#')
		return ;
	place = node->args->token->value;
	if (handle_exit_return_value_begin(&index, &is_negative, node)
		|| handle_exit_while_loop(&index, &number, &is_negative, node))
	{
		print_numeric_argument_required_exit(node, state);
		return ;
	}	
	if (handle_loop_exit_return_value(node, state, &index, &place))
		return ;
	exit((unsigned char) number * is_negative);
}

static void	exit_internals_with_pipes(t_node *node,
	t_state *state, int fd_input, int fd_output)
{
	int				how_many;

	dup_and_close(state, fd_input, fd_output);
	how_many = count_args_in_node(node);
	if (1 == how_many)
	{
		handle_exit_return_value_with_pipes(node, state);
	}
	if (how_many >= 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		exit(1);
	}
	exit(0);
}

static void	execute_exit_with_pipes(t_node *node, t_state *state)
{
	int		fd_output;
	int		fd_input;
	int		status;

	fd_input = dup(STDIN_FILENO);
	fd_output = dup(STDOUT_FILENO);
	g_outer_execution = 1;
	if (state->number_of_pipes)
		if_there_are_pipes(&fd_input, &fd_output, state);
	if_there_is_input_output(&fd_input, &fd_output, state);
	state->pids[state->number_of_execution] = fork();
	if (state->pids[state->number_of_execution] == 0)
		exit_internals_with_pipes(node, state, fd_input, fd_output);
	close(fd_input);
	close(fd_output);
	if (state->number_of_pipes)
		wait_pid_when_pipes(state, &status);
	else
	{
		waitpid(state->pids[state->number_of_execution], &status, 0);
		if (WIFEXITED(status))
			state->exit_status = WEXITSTATUS(status);
	}
	g_outer_execution = 0;
	clean_after_execution(state);
}

void	builtin_exit(t_node *node, t_state *state)
{
	if (state->number_of_pipes == 0)
		exit_internals(node, state);
	else
		execute_exit_with_pipes(node, state);
}
