/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:55:13 by helneff           #+#    #+#             */
/*   Updated: 2023/03/23 15:59:00 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../lexer.h"
#include "../../tool_functions/tool_functions.h"

int	read_expansion(t_lexer *lexer, t_token *token, t_state *state)
{
	char	*start;
	char	*temp;

	if (lexer->curr_char != '$')
		return (0);
	start = lexer->index;
	while (ft_isalnum(lexer->curr_char) || lexer->curr_char == '$'
		|| (lexer->index == start && ft_isalnum(lexer->index[1])))
		lexer->curr_char = *(++lexer->index);
	if (start[1] == '?')
		lexer->curr_char = *(lexer->index++);
	token->value = malloc(lexer->index - start + 1);
	if (!token->value)
		return (0);
	ft_strlcpy(token->value, start, lexer->index - start + 1);
	temp = token->value;
	token->value = expand_variables(token->value, state);
	free(temp);
	token->type = expansion_token;
	lexer->curr_char = 0;
	return (1);
}
