/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:02:40 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 15:54:37 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter/interpreter.h"
#include "unistd.h"
#include "../tool_functions/tool_functions.h"
#include "../execution/execution.h"

static void	execute_program2(t_node *node, t_state *state)
{
	int		fd_input;
	int		fd_output;
	int		status;

	ini_execute_program(&fd_input, &fd_output, state);
	if (state->number_of_pipes)
		if_there_are_pipes(&fd_input, &fd_output, state);
	if_there_is_input_output(&fd_input, &fd_output, state);
	state->pids[state->number_of_execution] = fork();
	if (state->pids[state->number_of_execution] == 0)
		child_execution(node, state, fd_input, fd_output);
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

void	execute_program(t_node *node, t_state *state)
{
	if (g_outer_execution == 9)
	{
		g_outer_execution = 0;
		return ;
	}
	execute_program2(node, state);
}
