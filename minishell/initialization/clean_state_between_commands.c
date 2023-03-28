/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_state_between_commands.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:49:02 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 17:20:33 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../state.h"
#include "../tool_functions/tool_functions.h"
#include "../initialization/initialization.h"

void	clean_state_between_commands(t_state *state)
{
	state->number_of_execution = -1;
	state->number_of_pipes = 0;
	state->output_file = 0;
	state->input_file = 0;
	state->input_set = 0;
	state->output_set = 0;
	state->continue_interpret = 1;
	enable_raw_mode(&state->original_terminal_settings);
}
