/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:05:46 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 13:28:44 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../interpreter.h"

void	invalid_action(t_node *ast, t_state *state)
{
	(void) ast;
	(void) state;
	ft_printf("Error interpreting input (Node: %d, Token: %d)\n",
		ast->type, ast->token->type);
	exit(1);
}
