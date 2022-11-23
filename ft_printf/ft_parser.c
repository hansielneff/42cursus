/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:44:55 by helneff           #+#    #+#             */
/*   Updated: 2022/11/17 17:47:39 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_parser.h"
#include "ft_arg_util.h"

static void	parse_arg_value(const char *fmt, t_argument *arg, va_list *ap)
{
	arg->specifier = *fmt;
	if (ft_strchr(SIGNED_INT_SPECIFIER, *fmt))
		arg->value.i = va_arg(*ap, int);
	else if (ft_strchr(UNSIGNED_INT_SPECIFIER, *fmt))
		arg->value.u = va_arg(*ap, unsigned int);
	else if (ft_strchr(CHAR_PTR_SPECIFIER, *fmt))
		arg->value.s = va_arg(*ap, char *);
	else if (ft_strchr(VOID_PTR_SPECIFIER, *fmt))
		arg->value.p = va_arg(*ap, void *);
	else
		arg->value.p = NULL;
}

static void	parse_arg_precision(const char **fmt, t_argument *arg, va_list *ap)
{
	if (**fmt != '.')
	{
		arg->precision = -1;
		return ;
	}
	++*fmt;
	if (**fmt == '*')
	{
		++*fmt;
		arg->precision = va_arg(*ap, int);
		return ;
	}
	arg->precision = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		++*fmt;
}

static void	parse_arg_width(const char **fmt, t_argument *arg, va_list *ap)
{
	if (**fmt == '*')
	{
		++*fmt;
		arg->width = va_arg(*ap, int);
		return ;
	}
	arg->width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		++*fmt;
}

static void	parse_arg_flags(const char **fmt, t_argument *arg)
{
	while (ft_strchr(ARG_FLAGS, **fmt))
	{
		if (**fmt == '-')
			arg->align_left = 1;
		else if (**fmt == '+')
			arg->force_sign = 1;
		else if (**fmt == ' ')
			arg->space_prefix = 1;
		else if (**fmt == '#')
			arg->hex_prefix = 1;
		else if (**fmt == '0')
			arg->zeros_padding = 1;
		++*fmt;
	}
}

t_argument	*parse_fmt_args(const char *fmt, va_list *ap)
{
	const size_t		arg_count = argument_count(fmt);
	t_argument			*args;
	size_t				i;

	args = ft_calloc(arg_count, sizeof(t_argument));
	if (!args)
		return (NULL);
	i = 0;
	while (i < arg_count)
	{
		fmt = find_next_arg(fmt);
		if (!fmt)
			break ;
		args[i].fmt_begin = (char *)fmt++;
		parse_arg_flags(&fmt, &args[i]);
		parse_arg_width(&fmt, &args[i], ap);
		parse_arg_precision(&fmt, &args[i], ap);
		parse_arg_value(fmt, &args[i], ap);
		args[i].fmt_end = (char *)++fmt;
		++i;
	}
	return (args);
}
