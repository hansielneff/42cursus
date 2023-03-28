/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:59:07 by helneff           #+#    #+#             */
/*   Updated: 2023/03/16 12:57:05 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	read_pipe(t_lexer *lexer, t_token *token)
{
	if (lexer->curr_char != '|')
		return (0);
	token->type = pipe_token;
	lexer->index++;
	lexer->curr_char = 0;
	return (1);
}
