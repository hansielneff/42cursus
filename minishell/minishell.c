/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:36:19 by helneff           #+#    #+#             */
/*   Updated: 2023/03/21 15:57:56 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "readline/readline.h"
#include "readline/history.h"

#include "interpreter/interpreter.h"
#include "initialization/initialization.h"
#include "signals/signals.h"
#include "state.h"

int	main(int argc, char **argv, char **envv)
{
	char	*input;
	t_lexer	*lexer;
	t_node	*ast;
	t_state	state;

	(void) argc;
	(void) argv;
	initialize(&state, envv);
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			not_signal_control_d(&state);
		if (ft_strlen(input) > 0)
			add_history(input);
		lexer = create_lexer(input);
		ast = parse_tokens(lexer, &state);
		interpret(ast, &state);
		free_ast(ast);
		free(lexer);
		free(input);
		clean_state_between_commands(&state);
	}
	return (0);
}
