/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out_1_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:03:03 by helneff           #+#    #+#             */
/*   Updated: 2023/02/28 13:31:56 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	read_redirect_out_1(t_lexer *lexer, t_token *token)
{
	if (lexer->curr_char != '>' || *(lexer->index + 1) == '>')
		return (0);
	token->type = redirect_out_1_token;
	lexer->index++;
	lexer->curr_char = 0;
	return (1);
}
