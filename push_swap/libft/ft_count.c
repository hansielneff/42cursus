/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:10:09 by helneff           #+#    #+#             */
/*   Updated: 2022/11/15 00:21:58 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(char *str, char c)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
		if (*(str++) == c)
			++count;
	return (count);
}
