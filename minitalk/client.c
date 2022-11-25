/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:46:06 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 16:29:34 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include "libft.h"

#define MSG_INTERVAL 256
#define RESPONSE_TIMEOUT 32

static void	send_char(pid_t server_pid, char c)
{
	size_t	i;

	i = 8;
	while (i > 0)
	{
		if ((c >> --i) & 0b00000001)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(MSG_INTERVAL);
	}
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Received confirmation from server\n");
		exit(0);
	}
}

int	main(int argc, char	*argv[])
{
	struct sigaction	disp;
	pid_t				server_pid;
	char				*msg;

	if (argc != 3)
	{
		ft_printf("usage: client server_pid message\n");
		return (1);
	}
	disp.__sigaction_u.__sa_handler = signal_handler;
	disp.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &disp, NULL);
	server_pid = ft_atoi(argv[1]);
	if (!server_pid || (size_t)ft_digitsl(server_pid, 10) < ft_strlen(argv[1]))
	{
		ft_printf("usage: client server_pid message\n");
		return (1);
	}
	msg = argv[2];
	while (*msg)
		send_char(server_pid, *(msg++));
	send_char(server_pid, '\0');
	sleep(RESPONSE_TIMEOUT);
	ft_printf("Server is unreachable\n");
	return (1);
}
