/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_from_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:11:19 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/10 14:35:24 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../state.h"
#include "../interpreter/interpreter.h"
#include "../tool_functions/tool_functions.h"

char	**command_from_node(t_node *node)
{
	int		how_many;
	char	**command;
	t_node	*runner;
	int		index;

	index = 0;
	how_many = count_args_in_node(node);
	command = malloc(sizeof(char *) * (how_many + 2));
	runner = node;
	while (runner)
	{
		command[index] = runner->token->value;
		++index;
		runner = runner->args;
	}
	command[index] = 0;
	return (command);
}
