/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:13:27 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/23 19:37:10 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../libft/libft.h"
#include "../tool_functions/tool_functions.h"
#include "unistd.h"

static t_node	*includes_dash_n(t_node *node)
{
	t_node	*argu;
	t_node	*to_return;
	int		index;

	argu = node->args;
	to_return = (void *) 0;
	while (argu)
	{
		if (argu->token->value[0] && argu->token->value[1])
		{
			if (argu->token->value[0] == '-' && argu->token->value[1] == 'n')
			{
				index = 2;
				while (argu->token->value[index])
				{
					if (argu->token->value[index] != 'n')
						return (to_return);
					++index;
				}
				to_return = argu;
			}
		}
		argu = argu->args;
	}
	return (to_return);
}

static void	echo_internals(t_node *node,
	t_state *state, int fd_input, int fd_output)
{
	t_node	*argument;
	t_node	*runner;
	int		first;

	dup_and_close(state, fd_input, fd_output);
	first = 0;
	argument = includes_dash_n(node);
	if (!argument)
		runner = node->args;
	else
		runner = argument->args;
	while (runner)
	{
		if (0 < first)
			ft_printf(" ");
		else
			first = 1;
		ft_printf("%s", runner->token->value);
		runner = runner->args;
	}
	if (!argument)
		ft_printf("\n");
	exit(0);
}

void	builtin_echo(t_node *node, t_state *state)
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
		echo_internals(node, state, fd_input, fd_output);
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
