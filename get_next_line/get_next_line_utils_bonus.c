/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:52:40 by helneff           #+#    #+#             */
/*   Updated: 2022/11/14 19:12:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		++s;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*(s++))
		++length;
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	while (--size > 0)
	{
		if (!*src)
			break ;
		*(dst++) = *(src++);
	}
	*dst = '\0';
	return (src_length);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
	while (size-- > (dst_len + 1) && *src != '\0')
		*(dst++ + dst_len) = *(src++);
	*(dst + dst_len) = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	result_size;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	result_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(result_size);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, result_size);
	ft_strlcat(result, s2, result_size);
	return (result);
}
