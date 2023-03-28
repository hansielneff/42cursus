/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:23:40 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 15:45:54 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../lexer.h"
#include "../../tool_functions/tool_functions.h"

int	read_expand_str(t_lexer *lexer, t_token *token, t_state *state)
{
	char	*start;
	char	*end;
	char	*temp;

	start = lexer->index;
	if (*start != '"')
		return (0);
	end = ++start;
	while (*end && *end != '"')
		end++;
	if (*end != '"')
		return (0);
	token->value = malloc(end - start + 1);
	if (!token->value)
		return (0);
	ft_strlcpy(token->value, start, end - start + 1);
	temp = token->value;
	token->value = expand_variables(token->value, state);
	free(temp);
	token->type = expand_str_token;
	lexer->index = end + 1;
	lexer->curr_char = 0;
	return (1);
}
