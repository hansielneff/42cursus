/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:37:41 by helneff           #+#    #+#             */
/*   Updated: 2022/11/17 17:48:25 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_arg_util.h"
#include "ft_writer.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_argument	*args;
	int			output_size;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	args = parse_fmt_args(fmt, &ap);
	va_end(ap);
	if (!args)
	{
		if (!argument_count(fmt))
		{
			ft_putstr_fd((char *)fmt, 1);
			return (ft_strlen(fmt));
		}
		return (0);
	}
	output_size = write_formatted_string(fmt, args);
	free(args);
	return (output_size);
}
