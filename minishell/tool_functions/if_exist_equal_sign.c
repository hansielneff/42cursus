/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_exist_equal_sign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:28:26 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/01 20:28:49 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	if_exist_equal_sign(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == '=')
			return (1);
		++index;
	}
	return (0);
}
