/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:45:54 by helneff           #+#    #+#             */
/*   Updated: 2022/10/28 18:52:12 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if ((size_t) ft_abs((char *) src - (char *) dst) >= n)
		while (n-- > 0)
			((char *) dst)[n] = ((char *) src)[n];
	return (dst);
}
