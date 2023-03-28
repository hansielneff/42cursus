/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:27:34 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/01 19:31:44 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tool_functions.h"

int	count_strings(char **commands)
{
	int	how_many;
	int	index;

	how_many = 0;
	index = 0;
	while (commands[index])
	{
		++index;
		++how_many;
	}
	return (how_many);
}
