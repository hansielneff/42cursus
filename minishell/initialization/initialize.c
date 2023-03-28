/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:22:02 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/14 16:27:30 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tool_functions/tool_functions.h"
#include "initialization.h"

//test include
#include "unistd.h"

void	initialize(t_state *state, char **envv)
{
	set_signal_handlers();
	initialize_envv(state, envv);
	enable_raw_mode(&state->original_terminal_settings);
	g_outer_execution = 0;
	state->number_of_execution = -1;
	state->number_of_pipes = 0;
	state->input_file = 0;
	state->output_file = 0;
	state->input_set = 0;
	state->output_set = 0;
	state->continue_interpret = 1;
	state->exit_status = 0;
}
