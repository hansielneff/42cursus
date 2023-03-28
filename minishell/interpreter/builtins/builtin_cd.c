/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:46:58 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/24 12:49:04 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "../../minishell.h"
#include "../libft/libft.h"
#include "builtins.h"
#include "../../tool_functions/tool_functions.h"

static void	lower_half_of_cd(t_node *node, t_state *state)
{
	char	*temp;

	if (exist_envv_variable("HOME", 1, state))
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	else if (exist_envv_variable("HOME=", 1, state))
		(void) node;
	else if (exist_envv_variable("HOME=", 0, state))
	{
		temp = get_var_from_envv("HOME", state);
		if (-1 == chdir(temp))
			print_cd_error(temp);
		safe_free_string(&temp);
	}
	else
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	}
}

static void	cd_internals(t_node *node, t_state *state)
{
	if (node->args)
	{
		if (node->args->token->value[0] == '\0')
			return ;
		if (-1 == chdir((char *) node->args->token->value))
			print_cd_error(node->args->token->value);
	}
	else
	{
		lower_half_of_cd(node, state);
	}
}

static void	cd_internals_with_pipes(t_node *node,
	t_state *state, int fd_input, int fd_output)
{
	dup_and_close(state, fd_input, fd_output);
	if (node->args)
	{
		if (node->args->token->value[0] == '\0')
			return ;
		if (-1 == chdir((char *) node->args->token->value))
			print_cd_error(node->args->token->value);
	}
	else
	{
		lower_half_of_cd(node, state);
	}
	exit(0);
}

static void	cd_with_pipes(t_node *node, t_state *state)
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
		cd_internals_with_pipes(node, state, fd_input, fd_output);
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

void	builtin_cd(t_node *node, t_state *state)
{
	if (state->number_of_pipes == 0)
		cd_internals(node, state);
	else
		cd_with_pipes(node, state);
}
