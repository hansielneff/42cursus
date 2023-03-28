/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_after_execution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:30:08 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 17:23:02 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter/interpreter.h"
#include "unistd.h"
#include "../initialization/initialization.h"

void	clean_after_execution(t_state *state)
{
	enable_raw_mode(&state->original_terminal_settings);
	if (state->input_set)
	{
		close(state->input_file);
		state->input_set = 0;
	}
	if (state->output_set)
	{
		close(state->output_file);
		state->output_set = 0;
	}
}
