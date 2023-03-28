/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_str_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:23:40 by helneff           #+#    #+#             */
/*   Updated: 2023/02/28 18:42:45 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../lexer.h"

int	read_raw_str(t_lexer *lexer, t_token *token)
{
	char	*start;
	char	*end;

	start = lexer->index;
	if (*start != '\'')
		return (0);
	end = ++start;
	while (*end && *end != '\'')
		end++;
	if (*end != '\'')
		return (0);
	token->value = malloc(end - start + 1);
	if (!token->value)
		return (0);
	ft_strlcpy(token->value, start, end - start + 1);
	token->type = raw_str_token;
	lexer->index = end + 1;
	lexer->curr_char = 0;
	return (1);
}
