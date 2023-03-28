/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numeric_argument_required_exit.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:38:55 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/20 20:43:48 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter/interpreter.h"
#include "../libft/libft.h"
#include "../initialization/initialization.h"

void	print_numeric_argument_required_exit(t_node *node, t_state *state)
{
	char	*place;

	place = node->args->token->value;
	if (state->number_of_pipes == 0)
		ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(place, 2);
	ft_putstr_fd(": numeric argument reguired\n", 2);
	if (state->number_of_pipes == 0)
	{
		disable_raw_mode(&state->original_terminal_settings);
		exit(255);
	}
}
