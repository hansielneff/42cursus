/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:17:46 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/20 13:44:03 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter.h"
#include "unistd.h"

void	pipe_action(t_node *node, t_state *state)
{
	if (!node->right || !node->left)
	{
		write(2, "minishell: syntax error\n", 25);
		state->continue_interpret = 0;
		return ;
	}
	pipe(&state->pipes[state->number_of_pipes * 2]);
	++(state->number_of_pipes);
}
