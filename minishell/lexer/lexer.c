/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:11:33 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 15:47:08 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "lexer.h"

t_lexer	*create_lexer(char	*str)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->input = str;
	lexer->index = str;
	lexer->curr_char = *str;
	return (lexer);
}

static int	consume_next_lexeme(t_lexer *lexer, t_token *token, t_state *state)
{
	return (
		read_whitespace(lexer, token)
		|| read_expansion(lexer, token, state)
		|| read_raw_str(lexer, token)
		|| read_expand_str(lexer, token, state)
		|| read_word(lexer, token)
		|| read_pipe(lexer, token)
		|| read_redirect_in_1(lexer, token)
		|| read_redirect_in_2(lexer, token)
		|| read_redirect_out_1(lexer, token)
		|| read_redirect_out_2(lexer, token)
	);
}

t_token	*get_next_token(t_lexer *lexer, t_state *state)
{
	t_token	*token;

	if (!*lexer->index)
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	ft_bzero(token, sizeof(t_token));
	while (lexer->curr_char)
		if (!consume_next_lexeme(lexer, token, state))
			handle_invalid(lexer, token);
	lexer->curr_char = *lexer->index;
	return (token);
}

t_token	*peek_next_token(t_lexer *lexer, t_state *state)
{
	const char	initial_char = lexer->curr_char;
	const char	*initial_index = lexer->index;
	t_token		*token;

	token = get_next_token(lexer, state);
	lexer->curr_char = (char)initial_char;
	lexer->index = (char *)initial_index;
	return (token);
}

void	skip_next_token(t_lexer *lexer, t_state *state)
{
	free_token(get_next_token(lexer, state));
}
