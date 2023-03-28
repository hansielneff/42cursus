/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_raw_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:28:02 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 13:31:02 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "termios.h"
#include "initialization.h"
#include "../tool_functions/tool_functions.h"

void	enable_raw_mode(struct termios *orig_termios)
{
	struct termios	raw;

	if (tcgetattr(STDIN_FILENO, orig_termios) == -1)
		error_exit("tcgetattr");
	raw = *orig_termios;
	raw.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		error_exit("tcsetattr");
}
