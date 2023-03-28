/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid_when_pipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:08:55 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/20 19:09:55 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../state.h"
#include "../tool_functions/tool_functions.h"

void	wait_pid_when_pipes(t_state *state, int *status)
{
	int	index;

	if (state->number_of_execution == state->number_of_pipes)
	{
		close_all_pipes(state);
		index = 0;
		while (index < (state->number_of_pipes + 1))
		{
			waitpid(state->pids[index], status, 0);
			if (WIFEXITED(*status))
				state->exit_status = WEXITSTATUS(*status);
			++index;
		}
	}
}
