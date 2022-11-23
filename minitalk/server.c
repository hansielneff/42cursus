/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:50:18 by helneff           #+#    #+#             */
/*   Updated: 2022/11/22 13:09:54 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include "libft.h"

static void	signal_handler(int signal, siginfo_t *siginfo, void *context)
{
	static char	*message = NULL;
	static char	buffer = 0;
	static int	signal_count = 0;

	(void)context;
	if (signal == SIGUSR1)
		buffer &= 0b11111110;
	else if (signal == SIGUSR2)
		buffer |= 0b00000001;
	if (++signal_count == 8)
	{
		if (!message)
			message = ft_strdup("");
		if (buffer == 0)
		{
			kill(siginfo->si_pid, SIGUSR1);
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
		}
		else
			message = ft_strpad(message, buffer, 1, 1);
		signal_count = 0;
	}
	buffer <<= 1;
}

int	main(void)
{
	struct sigaction	disp;

	ft_printf("%d\n", getpid());
	disp.__sigaction_u.__sa_sigaction = signal_handler;
	disp.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &disp, NULL);
	sigaction(SIGUSR2, &disp, NULL);
	while (pause() == -1)
		;
	return (1);
}
