/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_signal_control_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:12:52 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/09 15:53:56 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "../state.h"
#include "../initialization/initialization.h"

void	not_signal_control_d(t_state *state)
{
	ft_printf("\x1b[1A");
	ft_printf("\x1b[11C");
	ft_printf("exit\n");
	disable_raw_mode(&state->original_terminal_settings);
	exit(0);
}
