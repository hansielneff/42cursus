/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:42:07 by helneff           #+#    #+#             */
/*   Updated: 2022/10/30 12:58:16 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_length;
	size_t	sub_length;

	if (s == NULL)
		return (NULL);
	str_length = ft_strlen(s);
	if (str_length < (size_t) start)
		return (ft_strdup("\0"));
	sub_length = str_length - start;
	if (sub_length > len)
		sub_length = len;
	sub = malloc(sub_length + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_length + 1);
	return (sub);
}
