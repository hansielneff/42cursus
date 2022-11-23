/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:32:29 by helneff           #+#    #+#             */
/*   Updated: 2022/11/18 10:56:07 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_writer.h"
#include "ft_arg_util.h"

#include <unistd.h>

static char	*str_toupper(char *s)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		s[i] = ft_toupper(s[i]);
		++i;
	}
	return (s);
}

static char	*addr_to_str(void	*p)
{
	char	*result;
	char	*temp;

	temp = ft_based_ulltoa((unsigned long long)p, 16);
	if (!temp)
		return (NULL);
	result = ft_strjoin("0x", temp);
	free(temp);
	return (result);
}

static char	*arg_to_str(t_argument	*arg)
{
	char	*result;

	if (arg->specifier == 'c')
		result = ft_chrtostr((unsigned char)arg->value.i);
	else if (arg->specifier == 's' && arg->value.s)
		result = ft_strdup(arg->value.s);
	else if (arg->specifier == 'p')
		result = addr_to_str(arg->value.p);
	else if (arg->specifier == 'd' || arg->specifier == 'i')
		result = ft_itoa(arg->value.i);
	else if (arg->specifier == 'u')
		result = ft_utoa(arg->value.u);
	else if (arg->specifier == 'x')
		result = ft_based_ulltoa(arg->value.u, 16);
	else if (arg->specifier == 'X')
		result = str_toupper(ft_based_ulltoa(arg->value.u, 16));
	else if (arg->specifier == '%')
		result = ft_strdup("%");
	else
		result = NULL;
	return (result);
}

int	write_formatted_string(const char *fmt, t_argument	*args)
{
	const size_t	arg_count = argument_count(fmt);
	char			*arg_str;
	size_t			write_count;
	size_t			i;

	write_count = 0;
	i = 0;
	while (i < arg_count)
	{
		write_count += write(1, fmt, args[i].fmt_begin - fmt);
		arg_str = arg_to_str(&args[i]);
		if (!arg_str)
			write_count += write(1, "(null)", 6);
		else if (args[i].specifier == 'c' && *arg_str == '\0')
			write_count += write(1, arg_str, 1);
		else
			write_count += write(1, arg_str, ft_strlen(arg_str));
		if (arg_str)
			free(arg_str);
		fmt = args[i++].fmt_end;
	}
	write_count += write(1, fmt, ft_strlen(fmt));
	return (write_count);
}
