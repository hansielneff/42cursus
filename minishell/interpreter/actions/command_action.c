/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:05:46 by helneff           #+#    #+#             */
/*   Updated: 2023/03/24 12:42:56 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../interpreter.h"
#include "../builtins/builtins.h"
#include "../../execution/execution.h"

static int	is_builtin(t_token *token)
{
	const size_t	cmd_len = ft_strlen(token->value) + 1;

	return (
		!ft_strncmp(token->value, "echo", cmd_len)
		|| !ft_strncmp(token->value, "cd", cmd_len)
		|| !ft_strncmp(token->value, "pwd", cmd_len)
		|| !ft_strncmp(token->value, "export", cmd_len)
		|| !ft_strncmp(token->value, "unset", cmd_len)
		|| !ft_strncmp(token->value, "env", cmd_len)
		|| !ft_strncmp(token->value, "exit", cmd_len)
	);
}

static void	execute_builtin(t_node *node, t_state *state)
{
	const size_t	cmd_len = ft_strlen(node->token->value) + 1;

	++(state->number_of_execution);
	if (!ft_strncmp(node->token->value, "cd", cmd_len))
		builtin_cd(node, state);
	if (!ft_strncmp(node->token->value, "echo", cmd_len))
		builtin_echo(node, state);
	if (!ft_strncmp(node->token->value, "pwd", cmd_len))
		builtin_pwd(node, state);
	if (!ft_strncmp(node->token->value, "export", cmd_len))
		builtin_export(node, state);
	if (!ft_strncmp(node->token->value, "unset", cmd_len))
		builtin_unset(node, state);
	if (!ft_strncmp(node->token->value, "env", cmd_len))
		builtin_env(node, state);
	if (!ft_strncmp(node->token->value, "exit", cmd_len))
		builtin_exit(node, state);
}

void	command_action(t_node *node, t_state *state)
{
	if (is_builtin(node->token))
	{
		execute_builtin(node, state);
	}
	else
		execute_program(node, state);
}
