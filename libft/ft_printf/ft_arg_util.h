/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:55:44 by helneff           #+#    #+#             */
/*   Updated: 2022/11/16 07:52:47 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARG_UTIL_H
# define FT_ARG_UTIL_H

# include <stdlib.h>

# define ARG_SPECIFIERS			"cspdiuxX%"
# define ARG_FLAGS				"-+ #0"

# define SIGNED_INT_SPECIFIER	"idc"
# define UNSIGNED_INT_SPECIFIER	"uxX"
# define CHAR_PTR_SPECIFIER		"s"
# define VOID_PTR_SPECIFIER		"p"

int		is_arg(const char *fmt, size_t index);
size_t	argument_count(const char *fmt);
char	*find_next_arg(const char *fmt);

#endif
