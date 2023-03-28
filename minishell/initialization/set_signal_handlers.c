/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:41 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 17:25:56 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"
#include "../signals/signals.h"

void	set_signal_handlers(void)
{
	signal(SIGINT, signal_control_c);
	signal(SIGQUIT, signal_do_nothing);
	signal(SIGTSTP, signal_do_nothing);
}
