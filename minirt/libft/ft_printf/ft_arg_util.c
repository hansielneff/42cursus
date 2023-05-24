/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:54:48 by helneff           #+#    #+#             */
/*   Updated: 2022/11/18 10:56:05 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_arg_util.h"

int	is_arg(const char *fmt, size_t index)
{
	if (!fmt
		|| fmt[index] != '%'
		|| fmt[index + 1] == '\0'
		|| (index > 0 && is_arg(fmt, index - 1)))
		return (0);
	fmt += index + 1;
	while (ft_strchr(ARG_FLAGS, *fmt))
		++fmt;
	if (*fmt == '*')
		++fmt;
	else
		while (ft_isdigit(*fmt))
			++fmt;
	if (*fmt == '.')
	{
		++fmt;
		if (*fmt == '*')
			++fmt;
		else
			while (ft_isdigit(*fmt))
				++fmt;
	}
	return (ft_strchr(ARG_SPECIFIERS, *fmt) != NULL);
}

size_t	argument_count(const char *fmt)
{
	const size_t	str_len = ft_strlen(fmt);
	size_t			count;
	size_t			i;

	count = 0;
	i = 0;
	while (i < str_len)
		if (is_arg(fmt, i++))
			++count;
	return (count);
}

char	*find_next_arg(const char *fmt)
{
	const size_t	str_len = ft_strlen(fmt);
	size_t			i;

	i = 0;
	while (i < str_len)
	{
		if (is_arg(fmt, i))
			return ((char *)fmt + i);
		++i;
	}
	return (NULL);
}
