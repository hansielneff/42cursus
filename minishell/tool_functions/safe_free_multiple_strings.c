/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free_multiple_strings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:50:25 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/27 17:10:37 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "tool_functions.h"

void	safe_free_multiple_strings(char ***splitted)
{
	int	index;

	index = 0;
	if (*splitted)
	{
		while ((*splitted)[index])
		{
			safe_free_string(&(*splitted)[index]);
			++index;
		}
		free(*splitted);
		(*splitted) = NULL;
	}
}
