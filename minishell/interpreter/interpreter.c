/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:14:29 by helneff           #+#    #+#             */
/*   Updated: 2023/03/15 16:59:59 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "interpreter.h"
#include "unistd.h"
#include "../minishell.h"

void	no_action(t_node *node, t_state *state)
{
	(void) node;
	(void) state;
}

void	interpret(t_node *node, t_state *state)
{
	static const t_action	actions[] = {
	[invalid_node] = invalid_action,
	[expression_node] = no_action,
	[command_node] = command_action,
	[term_node] = no_action,
	[expansion_node] = no_action,
	[expand_str_node] = no_action,
	[raw_str_node] = no_action,
	[word_node] = no_action,
	[separator_node] = no_action,
	[pipe_node] = pipe_action,
	[redirect_node] = redirect_action,
	};

	if (!node || !state->continue_interpret)
		return ;
	actions[node->type](node, state);
	interpret(node->left, state);
	interpret(node->right, state);
}
