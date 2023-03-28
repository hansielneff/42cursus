/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:09:23 by helneff           #+#    #+#             */
/*   Updated: 2023/03/23 16:54:45 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static t_node	*get_next_redirects(t_lexer *lexer, t_state *state)
{
	t_node	*redirects;

	skip_whitespace(lexer, state);
	redirects = parse_redirect(lexer, state);
	if (redirects)
		redirects->left = get_next_redirects(lexer, state);
	return (redirects);
}

static t_node	*get_next_command(t_lexer *lexer, t_state *state)
{
	t_node	*command;
	t_node	*redirects;
	t_node	*last;

	redirects = get_next_redirects(lexer, state);
	last = redirects;
	while (last && last->left)
		last = last->left;
	skip_whitespace(lexer, state);
	command = parse_command(lexer, state);
	if (!command)
		return (NULL);
	if (last)
		last->left = get_next_redirects(lexer, state);
	else
	{
		redirects = get_next_redirects(lexer, state);
		last = redirects;
	}
	while (last && last->left)
		last = last->left;
	if (!last)
		return (command);
	last->left = command;
	return (redirects);
}

static t_node	*get_next_pipe(t_lexer *lexer, t_state *state)
{
	skip_whitespace(lexer, state);
	return (parse_pipe(lexer, state));
}

t_node	*parse_expression(t_lexer *lexer, t_state *state)
{
	t_node	*node;
	t_node	*next_node;
	t_token	*token;

	skip_whitespace(lexer, state);
	token = peek_next_token(lexer, state);
	if (!token)
		return (NULL);
	free_token(token);
	node = get_next_command(lexer, state);
	if (!node)
	{
		if (*lexer->input && state->continue_interpret)
			ft_printf("minishell: syntax error\n");
		return (NULL);
	}
	next_node = get_next_pipe(lexer, state);
	while (next_node)
	{
		next_node->left = node;
		next_node->right = get_next_command(lexer, state);
		node = next_node;
		next_node = get_next_pipe(lexer, state);
	}
	return (node);
}
