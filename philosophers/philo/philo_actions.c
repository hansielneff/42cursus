/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:11:22 by helneff           #+#    #+#             */
/*   Updated: 2023/03/22 14:13:00 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "philo_actions.h"
#include "logging.h"

void	action_think(t_pipe *pipe)
{
	pthread_mutex_lock(pipe->life_mutex);
	if (!pipe->is_dead)
		log_action(pipe->id, ACTION_THINK);
	pthread_mutex_unlock(pipe->life_mutex);
	usleep(10);
}

void	action_sleep(t_pipe *pipe)
{
	long	stop_time;
	long	time_left;

	pthread_mutex_lock(pipe->life_mutex);
	if (!pipe->is_dead)
	{
		time_left = pipe->prog_args->time_to_sleep;
		stop_time = current_time_ms() + time_left;
		log_action(pipe->id, ACTION_SLEEP);
		pthread_mutex_unlock(pipe->life_mutex);
		while (time_left > 0)
		{
			usleep(time_left / 2 * 1000);
			time_left = stop_time - current_time_ms();
		}
	}
	else
		pthread_mutex_unlock(pipe->life_mutex);
}

void	action_eat(t_pipe *pipe, int fork1, int fork2)
{
	long	stop_time;
	long	time_left;

	pthread_mutex_lock(pipe->life_mutex);
	if (!pipe->is_dead)
	{
		time_left = pipe->prog_args->time_to_eat;
		stop_time = current_time_ms() + time_left;
		pipe->prev_eat_time = current_time_ms();
		pipe->eat_count++;
		log_action(pipe->id, ACTION_EAT);
		pthread_mutex_unlock(pipe->life_mutex);
		while (time_left > 0)
		{
			usleep(time_left / 2 * 1000);
			time_left = stop_time - current_time_ms();
		}
	}
	else
		pthread_mutex_unlock(pipe->life_mutex);
	pthread_mutex_unlock(&pipe->forks[fork1]);
	pthread_mutex_unlock(&pipe->forks[fork2]);
}

void	action_take_fork(t_pipe *pipe, int fork)
{
	pthread_mutex_lock(pipe->life_mutex);
	if (pipe->is_dead)
	{
		pthread_mutex_unlock(pipe->life_mutex);
		return ;
	}
	pthread_mutex_unlock(pipe->life_mutex);
	pthread_mutex_lock(&pipe->forks[fork]);
	log_action(pipe->id, ACTION_TAKE_FORK);
}
