/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:46:01 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 14:36:01 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter.h"
#include "../libft/libft.h"
#include "fcntl.h"
#include "unistd.h"
#include "../tool_functions/tool_functions.h"
#include "stdio.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "../execution/execution.h"

static void	print_syntax_error_near_newline(void)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
}

void	redirect_1_in(t_node *node, t_state *state)
{
	char	*file;

	if (!node->args)
	{
		print_syntax_error_near_newline();
	}
	if (state->input_set)
	{
		close(state->input_file);
		state->input_set = 0;
	}
	file = find_last_argument_from_node(node);
	state->input_file = open(file, O_RDONLY);
	if (state->input_file < 0)
	{
		print_input_file_error(file);
		state->continue_interpret = 0;
		return ;
	}
	state->input_set = 1;
}

void	redirect_1_out(t_node *node, t_state *state)
{
	char	*file;

	if (!node->args)
	{
		print_syntax_error_near_newline();
	}
	if (state->output_set)
	{
		close(state->output_file);
		state->output_set = 0;
	}
	file = find_last_argument_from_node(node);
	state->output_file = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (state->output_file < 0)
	{
		print_output_file_error(file);
		state->continue_interpret = 0;
		return ;
	}
	state->output_set = 1;
}

void	redirect_2_out(t_node *node, t_state *state)
{
	char	*file;

	if (!node->args)
	{
		print_syntax_error_near_newline();
	}
	if (state->output_set)
	{
		close(state->output_file);
		state->output_set = 0;
	}
	file = find_last_argument_from_node(node);
	state->output_file = open(file, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (state->output_file < 0)
	{
		print_output_file_error(file);
		state->continue_interpret = 0;
		return ;
	}
	state->output_set = 1;
}

void	redirect_action(t_node *node, t_state *state)
{
	if (node->token->type == redirect_in_1_token)
	{
		redirect_1_in(node, state);
		return ;
	}
	if (node->token->type == redirect_in_2_token)
	{
		execute_heredoc(node, state);
		return ;
	}
	if (node->token->type == redirect_out_1_token)
	{
		redirect_1_out(node, state);
		return ;
	}
	if (node->token->type == redirect_out_2_token)
	{
		redirect_2_out(node, state);
		return ;
	}
}
