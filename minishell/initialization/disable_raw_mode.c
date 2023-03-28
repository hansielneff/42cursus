/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_raw_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:43:40 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 17:37:40 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termios.h"
#include "../tool_functions/tool_functions.h"
#include "unistd.h"
#include "initialization.h"

void	disable_raw_mode(struct termios *orig_termios)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios) == -1)
		error_exit("tcsetattr");
}
