/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:07:38 by helneff           #+#    #+#             */
/*   Updated: 2022/10/26 16:14:55 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*m;

	m = (unsigned char *) s;
	while (n-- > 0)
	{
		if (*m == (unsigned char) c)
			return ((void *) m);
		++m;
	}
	return (NULL);
}
