/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:31:33 by helneff           #+#    #+#             */
/*   Updated: 2023/03/22 13:51:03 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "sys/time.h"
#include "pthread.h"

#include "logging.h"

void	log_action(int philo_id, t_action action)
{
	static int				philo_died = 0;
	static pthread_mutex_t	talking_stick = PTHREAD_MUTEX_INITIALIZER;
	static const char		*action_strings[] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died"
	};

	pthread_mutex_lock(&talking_stick);
	if (!philo_died)
		printf("%08ld %d %s\n",
			current_time_ms(), philo_id, action_strings[action]);
	if (action == ACTION_DIE)
		philo_died = 1;
	pthread_mutex_unlock(&talking_stick);
}

unsigned long	current_time_ms(void)
{
	static pthread_mutex_t	start_time_mutex = PTHREAD_MUTEX_INITIALIZER;
	static time_t			start_time = 0;
	time_t					current_time;
	struct timeval			tv;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_lock(&start_time_mutex);
	if (!start_time)
		start_time = current_time;
	pthread_mutex_unlock(&start_time_mutex);
	return (current_time - start_time);
}
