/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:12:33 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 20:18:27 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../state.h"
#include "../libft/libft.h"
#include "../tool_functions/tool_functions.h"

void	replace_envv(char *string,
	char *search, int with_nul, t_state *state)
{
	int	index;
	int	length;

	length = ft_strlen(search);
	index = 0;
	while (state->envv[index])
	{
		if (!ft_strncmp(state->envv[index], search, length + with_nul))
		{
			safe_free_string(&(state->envv[index]));
			state->envv[index] = ft_strdup(string);
			return ;
		}
		++index;
	}
}
