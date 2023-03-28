/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:27:10 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/15 16:29:36 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter/interpreter.h"
#include "unistd.h"

void	close_all_pipes(t_state *state)
{
	int	index;

	index = 0;
	while (index < state->number_of_pipes)
	{
		close(state->pipes[(index * 2)]);
		close(state->pipes[(index * 2) + 1]);
		++index;
	}
}
