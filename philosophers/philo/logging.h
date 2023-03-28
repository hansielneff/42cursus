/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:30:43 by helneff           #+#    #+#             */
/*   Updated: 2023/01/25 18:14:42 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGING_H
# define LOGGING_H

# include "stdlib.h"

typedef enum e_action
{
	ACTION_TAKE_FORK,
	ACTION_EAT,
	ACTION_SLEEP,
	ACTION_THINK,
	ACTION_DIE
}	t_action;

void			log_action(int philo_id, t_action action);
unsigned long	current_time_ms(void);

#endif
