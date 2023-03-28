/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_control_c_heredoc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:44:41 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 15:42:56 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"
#include "readline/readline.h"
#include "../initialization/initialization.h"

void	signal_control_c_heredoc(int signal)
{
	(void) signal;
	ft_printf("\x1b[11D");
	exit(1);
}
