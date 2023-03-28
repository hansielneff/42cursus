/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args_in_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:31:58 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 12:55:28 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter/interpreter.h"
#include "tool_functions.h"

int	count_args_in_node(t_node *node)
{
	int		how_many;
	t_node	*runner;

	if (!node->args)
		return (0);
	how_many = 0;
	runner = node;
	while (runner)
	{
		if (runner->args)
		{
			runner = runner->args;
			++how_many;
			continue ;
		}
		break ;
	}
	return (how_many);
}
