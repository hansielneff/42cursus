/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:01:15 by helneff           #+#    #+#             */
/*   Updated: 2022/11/18 09:39:39 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*dupe;

	size = ft_strlen(s) + 1;
	dupe = malloc(size);
	if (dupe == NULL)
		return (NULL);
	ft_strlcpy(dupe, s, size);
	return (dupe);
}
