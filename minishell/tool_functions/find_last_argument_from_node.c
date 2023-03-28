/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_argument_from_node.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:32:05 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 14:35:08 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter/interpreter.h"

char	*find_last_argument_from_node(t_node *node)
{
	t_node	*runner;

	runner = node;
	while (runner->args)
		runner = runner->args;
	return (runner->token->value);
}
