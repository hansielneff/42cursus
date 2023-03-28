/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:20:09 by helneff           #+#    #+#             */
/*   Updated: 2023/03/22 14:52:35 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "philo_actions.h"
#include "logging.h"

static void	determine_fork_order(
	int philo_id, int philo_count, int *fork1, int *fork2)
{
	int	temp;

	if (philo_id == 1)
	{
		*fork1 = 0;
		*fork2 = 1;
	}
	else if (philo_id == philo_count)
	{
		*fork1 = 0;
		*fork2 = philo_count - 1;
	}
	else
	{
		*fork1 = philo_id - 1;
		*fork2 = philo_id;
		if (philo_id % 2 == 0)
		{
			usleep(5000);
			temp = *fork1;
			*fork1 = *fork2;
			*fork2 = temp;
		}
	}
}

void	*philo(void	*arg)
{
	t_pipe	*pipe;
	int		fork1;
	int		fork2;

	usleep(1000);
	pipe = arg;
	determine_fork_order(
		pipe->id, pipe->prog_args->philo_count, &fork1, &fork2);
	pthread_mutex_lock(pipe->life_mutex);
	pipe->prev_eat_time = current_time_ms();
	while (!pipe->is_dead)
	{
		pthread_mutex_unlock(pipe->life_mutex);
		if (!((unsigned int)fork2 >= pipe->prog_args->philo_count))
		{
			action_take_fork(pipe, fork1);
			action_take_fork(pipe, fork2);
			action_eat(pipe, fork1, fork2);
			action_sleep(pipe);
			action_think(pipe);
		}
		pthread_mutex_lock(pipe->life_mutex);
	}
	pthread_mutex_unlock(pipe->life_mutex);
	return (NULL);
}
