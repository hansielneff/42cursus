/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:34 by helneff           #+#    #+#             */
/*   Updated: 2023/03/14 17:42:01 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#include "arguments.h"

#include "stdio.h"

static int	is_in_range(char *num_str)
{
	int	digit_count;

	digit_count = 0;
	while (*num_str && ++digit_count <= 11)
		num_str++;
	num_str--;
	if (digit_count > 10 || (digit_count == 10 && *num_str > '5'))
		return (0);
	return (1);
}

int	parse_args(unsigned int argc, char *argv[], t_arguments *args)
{
	unsigned int	*arg;
	unsigned int	i;

	args->min_eat_count = 0;
	i = 1;
	while (i < argc || argc < 5)
	{
		if ((argc != 5 && argc != 6) || !is_in_range(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		arg = (unsigned int *)args + (i - 1);
		*arg = 0;
		while (*(argv[i]) >= '0' && *(argv[i]) <= '9')
			*arg = 10 * *arg + (*(argv[i]++) - '0');
		if (*(argv[i]) != '\0' || (i == 1 && args->philo_count == 0))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		++i;
	}
	return (0);
}
