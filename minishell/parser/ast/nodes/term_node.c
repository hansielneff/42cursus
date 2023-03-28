/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:23:50 by helneff           #+#    #+#             */
/*   Updated: 2023/03/15 13:45:40 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../ast.h"

static int	check_whitespace(t_lexer *lexer, t_state *state)
{
	t_token	*token;

	token = peek_next_token(lexer, state);
	if (token && token->type == whitespace_token)
	{
		free_token(token);
		return (1);
	}
	free_token(token);
	return (0);
}

static t_node	*get_next_part(t_lexer *lexer, t_state *state)
{
	t_node	*node;
	t_token	*token;

	node = NULL;
	token = peek_next_token(lexer, state);
	if (!token)
		return (NULL);
	if (token->type == expansion_token)
		node = parse_expansion(lexer, state);
	else if (token->type == expand_str_token)
		node = parse_expand_str(lexer, state);
	else if (token->type == raw_str_token)
		node = parse_raw_str(lexer, state);
	else if (token->type == word_token)
		node = parse_word(lexer, state);
	free_token(token);
	return (node);
}

void	append_to_term(t_node *term, t_node *node)
{
	char	*term_value;

	term_value = term->token->value;
	term->token->value = ft_strjoin(term_value, node->token->value);
	free(term_value);
	free_token(node->token);
	free(node);
}

t_node	*parse_term(t_lexer *lexer, t_state *state)
{
	t_node	*term;
	t_node	*node;

	term = get_next_part(lexer, state);
	node = term;
	while (lexer->curr_char && !check_whitespace(lexer, state) && node)
	{
		node = get_next_part(lexer, state);
		if (node)
			append_to_term(term, node);
	}
	return (term);
}
