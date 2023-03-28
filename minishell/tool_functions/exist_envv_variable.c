/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_envv_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:37:43 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 13:34:11 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../state.h"
#include "../libft/libft.h"

int	exist_envv_variable(char *string, int with_null, t_state *state)
{
	int		index;

	index = 0;
	while (state->envv[index])
	{
		if (!ft_strncmp(state->envv[index],
				string, ft_strlen(string) + with_null))
		{
			return (1);
		}
		++index;
	}
	return (0);
}
