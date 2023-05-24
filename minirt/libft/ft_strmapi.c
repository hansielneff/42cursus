/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:14:49 by helneff           #+#    #+#             */
/*   Updated: 2022/10/27 16:21:19 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	str_len;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	result = malloc(str_len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		result[i] = f(i, s[i]);
		++i;
	}
	result[i] = '\0';
	return (result);
}
