/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:27:19 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 18:54:01 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter.h"
#include "../../libft/libft.h"
#include "../../minishell.h"
#include "../../tool_functions/tool_functions.h"
#include "unistd.h"

static void	print_unset_error(char *string)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(string, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

void	unset_internals(t_node *node,
	t_state *state, int fd_input, int fd_output)
{
	t_node	*place;
	char	*temp;

	dup_and_close(state, fd_input, fd_output);
	if (1 > count_args_in_node(node))
		exit(0);
	place = node->args;
	while (place)
	{
		if (if_not_all_valid_printable(place->token->value, 0))
		{
			print_unset_error(place->token->value);
			place = place->args;
			continue ;
		}
		if (exist_envv_variable(place->token->value, 1, state))
			remove_variable_from_envv(place->token->value, state->envv, 1);
		temp = ft_strjoin(place->token->value, "=");
		if (exist_envv_variable(temp, 0, state))
			remove_variable_from_envv(temp, state->envv, 0);
		safe_free_string(&temp);
		place = place->args;
	}
	exit(0);
}

void	execute_unset(t_node *node, t_state *state)
{
	t_node	*place;
	char	*temp;

	if (1 > count_args_in_node(node))
		return ;
	place = node->args;
	while (place)
	{
		if (if_not_all_valid_printable(place->token->value, 0))
		{
			print_unset_error(place->token->value);
			place = place->args;
			continue ;
		}
		if (exist_envv_variable(place->token->value, 1, state))
			remove_variable_from_envv(place->token->value, state->envv, 1);
		temp = ft_strjoin(place->token->value, "=");
		if (exist_envv_variable(temp, 0, state))
			remove_variable_from_envv(temp, state->envv, 0);
		safe_free_string(&temp);
		place = place->args;
	}
}

void	execute_unset_with_pipes(t_node *node, t_state *state)
{
	int		fd_output;
	int		fd_input;
	int		status;

	(void) node;
	fd_input = dup(STDIN_FILENO);
	fd_output = dup(STDOUT_FILENO);
	g_outer_execution = 1;
	if (state->number_of_pipes)
		if_there_are_pipes(&fd_input, &fd_output, state);
	if_there_is_input_output(&fd_input, &fd_output, state);
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

void	builtin_unset(t_node *node, t_state *state)
{
	if (state->number_of_pipes > 0)
		execute_unset_with_pipes(node, state);
	if (state->number_of_pipes == 0)
		execute_unset(node, state);
}
