/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:57:06 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/23 16:49:49 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter.h"
#include "../../state.h"
#include "../../tool_functions/tool_functions.h"
#include "builtins.h"
#include "../../libft/libft.h"

static void	add_to_envv(char *string, t_state *state)
{
	int		how_many;
	char	**temp;

	how_many = count_strings(state->envv);
	temp = malloc(sizeof(char *) * (how_many + 2));
	how_many = 0;
	while (state->envv[how_many])
	{
		temp[how_many] = ft_strdup(state->envv[how_many]);
		++how_many;
	}
	temp[how_many] = ft_strdup(string);
	++how_many;
	temp[how_many] = 0;
	safe_free_multiple_strings(&state->envv);
	state->envv = temp;
}

void	export_args(t_node *node, t_state *state)
{
	t_node	*place;
	char	*temp;
	char	*temp2;

	place = node->args;
	while (place)
	{
		if (if_not_all_valid_printable(place->token->value, 1))
		{
			print_export_error(place->token->value);
			place = place->args;
			continue ;
		}
		temp = variable_up_to_equal_sign(place->token->value);
		temp2 = ft_strjoin(temp, "=");
		if (exist_envv_variable(temp, 1, state))
			replace_envv(place->token->value, temp, 1, state);
		else if (exist_envv_variable(temp2, 0, state))
			replace_envv(place->token->value, temp2, 0, state);
		else
			add_to_envv(place->token->value, state);
		safe_free_string(&temp);
		safe_free_string(&temp2);
		place = place->args;
	}
}

void	execute_export(t_node *node, t_state *state)
{
	if (!node->args)
		print_envv(1, state);
	else
		export_args(node, state);
}
