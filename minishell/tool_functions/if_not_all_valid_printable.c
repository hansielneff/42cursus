/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_not_all_valid_printable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:45:38 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/27 17:52:38 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	if_not_all_valid_printable(char *string, int equal_sign)
{
	int	index;

	index = 0;
	if ((string[index] >= '0' && string[index] <= '9') || string[index] == '=')
		return (1);
	while (string[index] != '\0')
	{
		if (equal_sign)
		{
			if (string[index] == '=')
			{
				++index;
				continue ;
			}
		}
		++index;
	}
	return (0);
}
