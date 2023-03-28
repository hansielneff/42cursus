/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:56:34 by helneff           #+#    #+#             */
/*   Updated: 2023/01/30 13:26:07 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "pthread.h"

# include "arguments.h"

typedef struct s_pipe
{
	pthread_t		thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*life_mutex;
	t_arguments		*prog_args;
	int				id;
	int				is_dead;
	unsigned int	eat_count;
	unsigned long	prev_eat_time;
}	t_pipe;

void	*philo(void	*arg);

#endif