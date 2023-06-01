/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:28:34 by helneff           #+#    #+#             */
/*   Updated: 2023/03/02 16:22:49 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubst(const char *s, const char *find, const char *replace)
{
	const char		*match = ft_strnstr(s, find, ft_strlen(s));
	size_t			result_size;
	char			*result;
	char			*before;
	char			*after;

	if (!match)
		return (NULL);
	before = ft_substr(s, 0, match - s);
	after = (char *)match + ft_strlen(find);
	result_size = ft_strlen(before) + ft_strlen(replace) + ft_strlen(after) + 1;
	result = malloc(result_size);
	if (!result)
		return (NULL);
	ft_strlcat(result, before, result_size);
	ft_strlcat(result, replace, result_size);
	ft_strlcat(result, after, result_size);
	free(before);
	return (result);
}
