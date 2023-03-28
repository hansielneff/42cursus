/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_there_is_input_output.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:05:41 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/20 19:08:07 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../state.h"
#include "unistd.h"

void	if_there_is_input_output(int *fd_input, int *fd_output,
	t_state *state)
{
	if (state->input_set)
	{
		close(*fd_input);
		*fd_input = dup(state->input_file);
	}
	if (state->output_set)
	{
		close(*fd_output);
		*fd_output = dup(state->output_file);
	}
}
