/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:26:58 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 16:09:45 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "../ast.h"

static int	skip_whitespace(t_lexer *lexer, t_state *state)
{
	int		amount;
	t_token	*token;

	amount = 0;
	token = peek_next_token(lexer, state);
	while (token && token->type == whitespace_token)
	{
		amount++;
		free_token(token);
		skip_next_token(lexer, state);
		token = peek_next_token(lexer, state);
	}
	free_token(token);
	return (amount);
}

t_node	*parse_command(t_lexer *lexer, t_state *state)
{
	t_node	*command;
	t_node	*arg;
	int		first_arg_whitespace;

	command = parse_term(lexer, state);
	if (!command)
		return (NULL);
	command->type = command_node;
	arg = command;
	first_arg_whitespace = skip_whitespace(lexer, state);
	arg->args = parse_term(lexer, state);
	if (arg->args && !first_arg_whitespace)
	{
		write(2, "Whitespace required before arguments!\n", 39);
		free_token(command->token);
		free(command);
		return (NULL);
	}
	while (arg->args)
	{
		skip_whitespace(lexer, state);
		arg = arg->args;
		arg->args = parse_term(lexer, state);
	}
	return (command);
}
