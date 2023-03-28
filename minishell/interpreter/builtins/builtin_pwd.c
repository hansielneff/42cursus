/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:47:58 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 12:32:23 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "builtins.h"
#include "../libft/libft.h" 
#include "../tool_functions/tool_functions.h"

void	pwd_internals(t_node *node, t_state *state, int fd_input, int fd_output)
{
	char	*pwd;

	(void) node;
	dup_and_close(state, fd_input, fd_output);
	pwd = getcwd(NULL, 0);
	if (NULL == pwd)
		perror("getcwd");
	else
	{
		ft_printf("%s\n", pwd);
		safe_free_string(&pwd);
	}
	exit(0);
}

void	builtin_pwd(t_node *node, t_state *state)
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
		pwd_internals(node, state, fd_input, fd_output);
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
