/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_variable_from_envv.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:52:37 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 16:54:01 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tool_functions.h"
#include "../libft/libft.h"

void	remove_variable_from_envv(char *string,
	char **envv, int with_null)
{
	int	index;
	int	index2;

	index = 0;
	while (envv[index])
	{
		if (!ft_strncmp(envv[index], string, ft_strlen(string) + with_null))
		{
			index2 = index;
			safe_free_string(&envv[index2]);
			while (envv[index2 + 1])
			{
				envv[index2] = envv[index2 + 1];
				++index2;
			}
			envv[index2] = 0;
			break ;
		}
		++index;
	}
}
