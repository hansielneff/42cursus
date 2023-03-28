/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:20:10 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/24 12:34:54 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter.h"
#include "../../state.h"
#include "../../tool_functions/tool_functions.h"
#include "../../libft/libft.h"
#include "../../initialization/initialization.h"
#include "builtins.h"

void	exit_internals(t_node *node, t_state *state)
{
	int	how_many;

	how_many = count_args_in_node(node);
	if (0 == how_many)
	{
		if (state->number_of_pipes == 0)
		{
			ft_putstr_fd("exit\n", 2);
			exit(0);
		}
	}
	if (1 == how_many)
	{
		handle_exit_return_value(node, state);
	}
	if (how_many >= 2)
	{
		if (state->number_of_pipes == 0)
			ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	}
}

int	handle_exit_while_loop(int *index,
	long long int *number, int *is_negative, t_node *node)
{
	char	*place;

	place = node->args->token->value;
	while (place[*index] && place[*index] >= '0' && place[*index] <= '9')
	{
		if (*number >= 922337203685477581)
			return (1);
		if (1 == (*is_negative))
		{
			if (*number == 922337203685477580 && ((place[*index] - '0') > 7))
				return (1);
		}
		else
		{
			if (*number == 922337203685477580 && ((place[*index] - '0') > 8))
				return (1);
		}
		*number = (*number * 10) + (place[*index] - '0');
		++(*index);
	}
	return (0);
}

int	handle_exit_return_value_begin(int *index,
	int *is_negative, t_node *node)
{
	char	*place;

	place = node->args->token->value;
	while (place[*index] && place[*index] <= 32)
		++(*index);
	if (place[*index] && (place[*index] == '-' || place[*index] == '+'))
	{
		if (place[*index] == '-')
			*is_negative = -1;
		++(*index);
		if (place[*index] == '\0')
			return (1);
	}
	return (0);
}

void	handle_exit_return_value(t_node *node, t_state *state)
{
	int				index;
	long long int	number;
	int				is_negative;
	char			*place;

	initialize_handle_exit_return_value_values(&index, &number, &is_negative);
	if (node->args->token->value[0] == '#')
		exit(0);
	place = node->args->token->value;
	if (handle_exit_return_value_begin(&index, &is_negative, node)
		|| handle_exit_while_loop(&index, &number, &is_negative, node))
	{
		print_numeric_argument_required_exit(node, state);
		return ;
	}	
	if (handle_loop_exit_return_value(node, state, &index, &place))
		return ;
	if (state->number_of_pipes == 0)
	{
		ft_printf("%s\n", "exit");
		disable_raw_mode(&state->original_terminal_settings);
		exit((unsigned char) number * is_negative);
	}
	state->exit_status = (unsigned char) number * is_negative;
}
