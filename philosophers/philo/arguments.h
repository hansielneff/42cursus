/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:54:11 by helneff           #+#    #+#             */
/*   Updated: 2023/01/26 17:57:55 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

typedef struct s_arguments
{
	unsigned int	philo_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	min_eat_count;
}	t_arguments;

int	parse_args(unsigned int argc, char *argv[], t_arguments *args);

#endif
