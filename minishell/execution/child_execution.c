/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:51:28 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/27 17:41:16 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interpreter/interpreter.h"
#include "../tool_functions/tool_functions.h"
#include "unistd.h"
#include "../libft/libft.h"
#include "../state.h"
#include "../initialization/initialization.h"

static void	search_path(char **envp, char **path)
{
	int	index;

	*path = (void *) 0;
	index = 0;
	while (envp[index])
	{
		if (ft_strnstr(envp[index], "PATH=", 5))
		{
			*path = ft_strdup(&envp[index][5]);
			break ;
		}
		++index;
	}
}

static void	find_how_many_paths(char **paths, int *how_many_paths)
{
	(*how_many_paths) = 0;
	if (paths)
	{
		while (paths[(*how_many_paths)])
		{
			++(*how_many_paths);
		}
	}
}

static void	go_through_paths(char **command, char **full_paths, t_state *state)
{
	int		index;
	char	*path;
	int		found;

	found = 0;
	index = 0;
	while (full_paths[index])
	{
		if (full_paths[index] && full_paths[index][0] != '\0')
			path = ft_strjoin(full_paths[index], command[0]);
		else
			path = ft_strdup(command[0]);
		if (access(path, F_OK) == 0 && access(path, X_OK) != 0)
			found = 1;
		execve(path, command, state->envv);
		safe_free_string(&path);
		++index;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command[0], 2);
	if (found)
		ft_putstr_fd(": Permission denied\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
}

char	**get_env_paths(char **envv)
{
	char	*path;
	char	**paths;
	char	**fpaths;
	int		index;
	int		how_many_paths;

	search_path(envv, &path);
	paths = ft_split(path, ':');
	safe_free_string(&path);
	find_how_many_paths(paths, &how_many_paths);
	fpaths = malloc(sizeof(char *) * (how_many_paths + 1));
	index = 0;
	while (index < how_many_paths)
	{
		fpaths[index] = ft_strjoin(paths[index], "/");
		++index;
	}
	fpaths[how_many_paths] = 0;
	safe_free_multiple_strings(&paths);
	return (fpaths);
}

void	child_execution(t_node	*node, t_state *state,
	int fd_input, int fd_output)
{
	char	**command;
	char	**full_paths;

	disable_raw_mode(&state->original_terminal_settings);
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close(fd_input);
	close(fd_output);
	close_all_pipes(state);
	command = command_from_node(node);
	if (command[0])
		execve(command[0], command, state->envv);
	child_check_errors(command);
	full_paths = get_env_paths(state->envv);
	go_through_paths(command, full_paths, state);
	safe_free_multiple_strings(&command);
	safe_free_multiple_strings(&full_paths);
	exit(127);
}
