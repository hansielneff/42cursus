/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_from_envv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:34:15 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/23 19:36:59 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "stdio.h"
#include "../libft/libft.h"
#include "tool_functions.h"

char	*get_var_from_envv(char *string, t_state *state)
{
	char	**place;
	char	*begin;
	char	*temp;

	place = state->envv;
	while (*place)
	{
		temp = ft_strjoin(string, "=");
		if (!ft_strncmp(*place,
				temp, ft_strlen(string)))
		{
			safe_free_string(&temp);
			begin = *place;
			while ((*begin) != '=')
				++begin;
			++begin;
			return (ft_strdup(begin));
		}
		++place;
		safe_free_string(&temp);
	}
	return (NULL);
}
