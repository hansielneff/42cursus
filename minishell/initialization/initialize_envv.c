/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_envv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:42:03 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 17:26:50 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"
#include "../tool_functions/tool_functions.h"

void	initialize_envv(t_state *state, char **envv)
{
	int		how_many;
	char	**place;

	how_many = count_strings(envv);
	state->envv = malloc(sizeof(char *) * (how_many + 1));
	place = state->envv;
	while (*envv)
	{
		*place = ft_strdup(*envv);
		++place;
		++envv;
	}
	*place = 0;
}
