/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_do_nothing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:47:48 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/09 14:37:56 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "stdio.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "../libft/libft.h"
#include "../minishell.h"

void	signal_do_nothing(int signal)
{
	(void) signal;
	if (g_outer_execution)
	{
		ft_printf("%s", "^\\Quit: 3\n");
		return ;
	}
	rl_redisplay();
}
