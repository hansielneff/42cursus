/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_execute_program.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:58:57 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/20 19:00:31 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "../interpreter/interpreter.h"

void	ini_execute_program(int *fd_input, int *fd_output, t_state *state)
{
	g_outer_execution = 1;
	++(state->number_of_execution);
	*fd_input = dup(STDIN_FILENO);
	*fd_output = dup(STDOUT_FILENO);
}
