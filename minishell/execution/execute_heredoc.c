/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:39:27 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 15:51:34 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter/interpreter.h"
#include "fcntl.h"
#include "../signals/signals.h"
#include "stdlib.h"
#include "../tool_functions/tool_functions.h"
#include "stdio.h"
#include "readline/readline.h"
#include "../libft/libft.h"
#include "unistd.h"
#include "../initialization/initialization.h"

static void	run_heredoc_as_child(char *end_of_file)
{
	int		fd;
	char	*line_read;

	signal(SIGINT, signal_control_c_heredoc);
	fd = open(".temp_heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		print_output_file_error("heredoc");
	while (42)
	{
		line_read = readline("> ");
		if (!line_read)
		{
			ft_printf("\x1b[1A");
			ft_printf("\x1b[2C");
			break ;
		}
		if (0 == ft_strncmp(end_of_file, line_read, ft_strlen(line_read) + 1))
			break ;
		write(fd, line_read, ft_strlen(line_read));
		write(fd, "\n", 1);
		safe_free_string(&line_read);
	}
	safe_free_string(&line_read);
	close(fd);
	exit (0);
}

static void	rest_of_execute_heredoc(t_state *state)
{
	if (state->exit_status == 0)
	{
		if (state->input_set)
		{
			close(state->input_file);
			state->input_set = 0;
		}
		state->input_file = open(".temp_heredoc", O_RDONLY);
		if (state->input_file > 0)
			state->input_set = 1;
	}
	else
	{
		g_outer_execution = 9;
		return ;
	}
	g_outer_execution = 0;
}

void	execute_heredoc(t_node *node, t_state *state)
{
	int		pid;
	int		temp_exit_status;

	pid = fork();
	if (0 == pid)
		run_heredoc_as_child(node->args->token->value);
	waitpid(pid, &temp_exit_status, 0);
	if (WIFEXITED(temp_exit_status))
		state->exit_status = WEXITSTATUS(temp_exit_status);
	rest_of_execute_heredoc(state);
}
