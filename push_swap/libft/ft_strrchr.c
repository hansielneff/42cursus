/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:55:15 by helneff           #+#    #+#             */
/*   Updated: 2022/11/15 20:47:25 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*latest;

	latest = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			latest = (char *) s;
		++s;
	}
	if ((unsigned char)c == '\0')
		return ((char *) s);
	return (latest);
}
