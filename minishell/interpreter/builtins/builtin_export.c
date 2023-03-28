/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:05:35 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 19:10:32 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../interpreter/interpreter.h"
#include "../../tool_functions/tool_functions.h"
#include "../../libft/libft.h"
#include "unistd.h"
#include "builtins.h"

void	print_export_error(char *string)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(string, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

static void	execute_export_with_pipes(t_node *node,
	t_state *state, int fd_input, int fd_output)
{
	dup_and_close(state, fd_input, fd_output);
	if (!node->args)
		print_envv(1, state);
	else
		export_args(node, state);
	exit(0);
}

static void	launch_export_pipes(t_node *node, t_state *state)
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
		execute_export_with_pipes(node, state, fd_input, fd_output);
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

void	builtin_export(t_node *node, t_state *state)
{
	if (state->number_of_pipes == 0)
		execute_export(node, state);
	if (state->number_of_pipes != 0)
		launch_export_pipes(node, state);
}
