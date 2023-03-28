/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_there_are_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:02:20 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/20 19:04:51 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../state.h"
#include "unistd.h"

void	if_there_are_pipes(int *fd_input, int *fd_output, t_state *state)
{
	if (state->number_of_execution == 0)
	{
		close(*fd_output);
		*fd_output = dup(state->pipes[1]);
	}
	else if (state->number_of_execution > 0
		&& (state->number_of_execution
			< state->number_of_pipes))
	{
		close(*fd_input);
		close(*fd_output);
		*fd_input = dup(state->pipes[(state->number_of_execution - 1) * 2]);
		*fd_output = dup(state->pipes[(state->number_of_execution * 2) + 1]);
	}
	else if (state->number_of_execution == state->number_of_pipes)
	{
		close(*fd_input);
		*fd_input = dup(state->pipes[((state->number_of_execution - 1) * 2)]);
	}
}
