/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_str_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:11:52 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 16:14:41 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

t_node	*parse_raw_str(t_lexer *lexer, t_state *state)
{
	t_node	*node;
	t_token	*token;

	token = peek_next_token(lexer, state);
	if (!token || token->type != raw_str_token)
	{
		free_token(token);
		return (NULL);
	}
	skip_next_token(lexer, state);
	node = create_node(token, NULL, NULL);
	if (!node)
	{
		free_token(token);
		free(node);
		return (NULL);
	}
	return (node);
}
