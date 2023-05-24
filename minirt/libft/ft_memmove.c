/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:26:11 by helneff           #+#    #+#             */
/*   Updated: 2022/10/26 16:10:44 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_cp;
	char	*src_cp;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_cp = (char *) dst;
	src_cp = (char *) src;
	if (dst_cp > src_cp)
		while (n-- > 0)
			dst_cp[n] = src_cp[n];
	else
		while (n-- > 0)
			*(dst_cp++) = *(src_cp++);
	return (dst);
}
