/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:46:11 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 15:56:53 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../state.h"

t_node	*parse_tokens(t_lexer *lexer, t_state *state)
{
	return (parse_expression(lexer, state));
}
