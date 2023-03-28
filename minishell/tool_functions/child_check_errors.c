/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_check_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:19:52 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/27 16:24:50 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "../libft/libft.h"
#include "../tool_functions/tool_functions.h"

void	child_check_errors(char **command)
{
	if (command[0] && (command[0][0] == '.' || command[0][0] == '/')
		&& access(command[0], F_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		safe_free_multiple_strings(&command);
		exit(1);
	}
	if (command[0] && (command[0][0] == '.' || command[0][0] == '/')
		&& access(command[0], F_OK) == 0 && access(command[0], X_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command[0], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		safe_free_multiple_strings(&command);
		exit(1);
	}
}
