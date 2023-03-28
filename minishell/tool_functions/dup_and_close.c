/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:24:25 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 12:34:13 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "../tool_functions/tool_functions.h"

void	dup_and_close(t_state *state, int fd_input, int fd_output)
{
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close(fd_input);
	close(fd_output);
	close_all_pipes(state);
}
