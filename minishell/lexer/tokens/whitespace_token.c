/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:20:11 by helneff           #+#    #+#             */
/*   Updated: 2023/02/28 13:32:09 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	read_whitespace(t_lexer *lexer, t_token *token)
{
	size_t	skip_count;

	skip_count = 0;
	while (lexer->curr_char == ' ')
	{
		lexer->curr_char = *(++lexer->index);
		skip_count++;
	}
	if (!skip_count)
		return (0);
	token->type = whitespace_token;
	lexer->curr_char = 0;
	return (1);
}
