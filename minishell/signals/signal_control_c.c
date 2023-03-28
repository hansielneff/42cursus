/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_control_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:25:57 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 15:21:36 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "signals.h"
#include "unistd.h"
#include "stdio.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "../libft/libft.h"

void	signal_control_c(int signal)
{
	(void) signal;
	if (g_outer_execution == 1)
	{
		ft_printf("%s", "^C\n");
		return ;
	}
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}
