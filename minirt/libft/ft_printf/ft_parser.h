/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:44:10 by helneff           #+#    #+#             */
/*   Updated: 2022/11/17 17:47:52 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdarg.h>

typedef union u_arg_value
{
	int				i;
	unsigned int	u;
	char			*s;
	void			*p;
}	t_arg_value;

typedef struct s_argument
{
	int			align_left;
	int			force_sign;
	int			space_prefix;
	int			hex_prefix;
	int			zeros_padding;
	int			width;
	int			precision;
	char		specifier;
	char		*fmt_begin;
	char		*fmt_end;
	t_arg_value	value;
}	t_argument;

t_argument	*parse_fmt_args(const char *fmt, va_list *ap);

#endif
