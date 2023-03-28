/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:11:22 by helneff           #+#    #+#             */
/*   Updated: 2023/01/30 14:18:58 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ACTIONS_H
# define PHILO_ACTIONS_H

# include "philosophers.h"

void	action_think(t_pipe *pipe);
void	action_sleep(t_pipe *pipe);
void	action_eat(t_pipe *pipe, int fork1, int fork2);
void	action_take_fork(t_pipe *pipe, int fork);

#endif
