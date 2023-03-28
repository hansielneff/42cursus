/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:29:54 by helneff           #+#    #+#             */
/*   Updated: 2023/03/23 16:53:52 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "libft.h"

#include "../../parser.h"
#include "../ast.h"

static void	skip_whitespace(t_lexer *lexer, t_state *state)
{
	t_token	*token;

	token = peek_next_token(lexer, state);
	while (token && token->type == whitespace_token)
	{
		free_token(token);
		skip_next_token(lexer, state);
		token = peek_next_token(lexer, state);
	}
	free_token(token);
}

static void	handle_errors(t_node **node, t_token *token, t_state *state)
{
	if (!*node || !(*node)->args)
		free_token(token);
	if (!(*node)->args)
	{
		if (state->continue_interpret)
			write(2, "minishell: syntax error\n", 25);
		state->continue_interpret = 0;
		free(*node);
		*node = NULL;
	}
}

t_node	*parse_redirect(t_lexer *lexer, t_state *state)
{
	t_node	*node;
	t_token	*token;

	token = peek_next_token(lexer, state);
	if (!token || (
			token->type != redirect_in_1_token
			&& token->type != redirect_in_2_token
			&& token->type != redirect_out_1_token
			&& token->type != redirect_out_2_token))
	{
		free_token(token);
		return (NULL);
	}
	skip_next_token(lexer, state);
	skip_whitespace(lexer, state);
	node = create_node(token, NULL, NULL);
	node->args = parse_term(lexer, state);
	handle_errors(&node, token, state);
	if (node)
		node->type = redirect_node;
	return (node);
}
