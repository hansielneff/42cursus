/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:26:30 by helneff           #+#    #+#             */
/*   Updated: 2022/10/28 16:04:47 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t size)
{
	int	i;

	if (*little == '\0')
		return ((char *) big);
	if (size == 0)
		return (NULL);
	while (*big != '\0' && size > 0)
	{
		i = 0;
		while (big[i] != '\0' && size - i > 0)
		{
			if (big[i] != little[i])
				break ;
			if (little[i + 1] == '\0')
				return ((char *) big);
			++i;
		}
		++big;
		--size;
	}
	return (NULL);
}
