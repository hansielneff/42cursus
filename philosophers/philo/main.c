/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:13:14 by helneff           #+#    #+#             */
/*   Updated: 2023/03/22 19:09:19 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "string.h"

#include "philosophers.h"
#include "logging.h"

static int	handle_philo_death(
	t_arguments *args, t_pipe *philos, size_t philo_index)
{
	size_t	i;

	pthread_mutex_lock(philos[philo_index].life_mutex);
	if (current_time_ms()
		- philos[philo_index].prev_eat_time > args->time_to_die)
	{
		philos[philo_index].is_dead = 1;
		pthread_mutex_unlock(philos[philo_index].life_mutex);
		i = 0;
		while (i < (size_t)args->philo_count)
		{
			if (i != philo_index)
			{
				pthread_mutex_lock(philos[i].life_mutex);
				philos[i].is_dead = 1;
				pthread_mutex_unlock(philos[i].life_mutex);
			}
			++i;
		}
		log_action(philos[philo_index].id, ACTION_DIE);
		return (philos[philo_index].id);
	}
	pthread_mutex_unlock(philos[philo_index].life_mutex);
	return (0);
}

static void	track_simulation(t_arguments *args, t_pipe *philos)
{
	int		all_satisfied;
	size_t	i;

	i = 0;
	all_satisfied = 1;
	while (1)
	{
		if (handle_philo_death(args, philos, i))
			break ;
		pthread_mutex_lock(philos[i].life_mutex);
		if (philos[i].eat_count < args->min_eat_count)
			all_satisfied = 0;
		pthread_mutex_unlock(philos[i].life_mutex);
		if (++i == args->philo_count)
		{
			i = 0;
			if (args->min_eat_count && all_satisfied)
				break ;
			all_satisfied = 1;
		}
	}
}

static int	init_philos_and_forks(
	t_arguments *args, t_pipe **philos, pthread_mutex_t **forks)
{
	const pthread_mutex_t	*life_mutexes = NULL;
	const size_t			count = args->philo_count;
	size_t					i;
	int						ret;

	ret = 0;
	*philos = malloc(sizeof(t_pipe) * count);
	*forks = malloc(sizeof(pthread_mutex_t) * count);
	if (*philos && *forks)
		life_mutexes = malloc(sizeof(pthread_mutex_t) * count);
	if (!life_mutexes)
		return (1);
	memset(*philos, 0, sizeof(t_pipe) * count);
	i = 0;
	while (i < count)
	{
		(*philos + i)->forks = *forks;
		(*philos + i)->life_mutex = (pthread_mutex_t *)life_mutexes + i;
		(*philos + i)->prog_args = args;
		(*philos + i)->id = i + 1;
		ret += pthread_create(&(*philos + i)->thread, NULL, philo, *philos + i);
		ret += pthread_mutex_init((*philos + i)->life_mutex, NULL);
		ret += pthread_mutex_init(*forks + i++, NULL);
	}
	return (ret);
}

static void	free_philos_and_forks(
	t_arguments *args, t_pipe *philos, pthread_mutex_t *forks, int alloc_failed)
{
	size_t	i;

	i = 0;
	while (philos && i < args->philo_count)
	{
		pthread_join(philos[i].thread, NULL);
		if (!alloc_failed)
			pthread_mutex_destroy(philos[i].life_mutex);
		++i;
	}
	i = 0;
	while (forks && i < args->philo_count)
		pthread_mutex_destroy(&(forks[i++]));
	if (!alloc_failed)
		free(philos->life_mutex);
	free(philos);
	free(forks);
}

int	main(int argc, char	*argv[])
{
	t_arguments				args;
	static t_pipe			*philos = NULL;
	static pthread_mutex_t	*forks = NULL;
	static int				alloc_failed = 0;
	static unsigned int		i = 0;

	if (parse_args(argc, argv, &args))
		return (1);
	if (argc == 6 && args.philo_count > 0 && args.min_eat_count == 0)
		return (0);
	alloc_failed = init_philos_and_forks(&args, &philos, &forks);
	if (!alloc_failed)
	{
		track_simulation(&args, philos);
		while (i < args.philo_count)
		{
			pthread_mutex_lock(philos[i].life_mutex);
			philos[i].is_dead = 1;
			pthread_mutex_unlock(philos[i++].life_mutex);
		}
	}
	else
		write(2, "Allocation error!\n", 18);
	free_philos_and_forks(&args, philos, forks, alloc_failed);
	return (0);
}
