/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_up_to_equal_sign.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:40:38 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/23 16:51:27 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*variable_up_to_equal_sign(char *string)
{
	int		index;
	char	*temp;

	index = 0;
	while (string[index] && string[index] != '=')
		++index;
	temp = malloc(sizeof(char) * (index + 1));
	index = 0;
	while (string[index] && string[index] != '=')
	{
		temp[index] = string[index];
		++index;
	}
	temp[index] = '\0';
	return (temp);
}
