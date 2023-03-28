/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:23:40 by helneff           #+#    #+#             */
/*   Updated: 2023/02/28 13:32:14 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../lexer.h"

static int	is_meta_char(char c)
{
	return (c == ' ' || c == '$' || c == '\'' || c == '"'
		|| c == '|' || c == '<' || c == '>');
}

int	read_word(t_lexer *lexer, t_token *token)
{
	char	*start;

	start = lexer->index;
	while (*lexer->index && !is_meta_char(lexer->curr_char))
		lexer->curr_char = *(++lexer->index);
	if (start == lexer->index)
		return (0);
	token->value = malloc(lexer->index - start + 1);
	if (!token->value)
		return (0);
	ft_strlcpy(token->value, start, lexer->index - start + 1);
	token->type = word_token;
	lexer->curr_char = 0;
	return (1);
}
