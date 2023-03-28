/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in_2_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:03:01 by helneff           #+#    #+#             */
/*   Updated: 2023/02/28 13:31:53 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	read_redirect_in_2(t_lexer *lexer, t_token *token)
{
	if (lexer->curr_char != '<' || *(lexer->index + 1) != '<')
		return (0);
	token->type = redirect_in_2_token;
	lexer->index += 2;
	lexer->curr_char = 0;
	return (1);
}
