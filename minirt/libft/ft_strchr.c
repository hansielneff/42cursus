/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:42:37 by helneff           #+#    #+#             */
/*   Updated: 2022/11/15 20:41:10 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *) s);
		++s;
	}
	if ((unsigned char)c == '\0')
		return ((char *) s);
	return (NULL);
}
