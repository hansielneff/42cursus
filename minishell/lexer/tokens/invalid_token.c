/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:35:00 by helneff           #+#    #+#             */
/*   Updated: 2023/02/28 13:31:33 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	handle_invalid(t_lexer *lexer, t_token *token)
{
	token->type = invalid_token;
	lexer->curr_char = 0;
}
