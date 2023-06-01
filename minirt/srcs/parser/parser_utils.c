/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:50:31 by helneff           #+#    #+#             */
/*   Updated: 2023/05/24 12:16:04 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "parser.h"

int	eat_whitespace(const char **elem)
{
	if (**elem != ' ')
		return (1);
	while (**elem == ' ')
		(*elem)++;
	return (0);
}

int	eat_comma(const char **elem)
{
	if (**elem != ',')
		return (1);
	(*elem)++;
	return (0);
}

static double	convert_to_double(int integer, int decimal, int decimal_count)
{
	double	fraction;

	fraction = decimal;
	while (decimal_count-- > 0)
		fraction *= 0.1;
	return (integer + fraction);
}

static int	parse_decimal(const char **elem, double *decimal)
{
	int	decimal_count;

	if (!ft_isdigit(*(++(*elem))))
		return (-1);
	*decimal = 0;
	decimal_count = 0;
	while (ft_isdigit(**elem))
	{
		*decimal = *decimal * 10 + (*((*elem)++) - '0');
		decimal_count++;
	}
	return (decimal_count);
}

int	parse_num(const char **elem, double *result)
{
	const int	sign = 1 - 2 * (**elem == '-');
	int			integer;
	int			decimal_count;
	double		decimal;

	if (**elem == '-' || **elem == '+')
		(*elem)++;
	if (!ft_isdigit(**elem))
		return (1);
	integer = 0;
	while (ft_isdigit(**elem))
		integer = integer * 10 + (*((*elem)++) - '0');
	decimal = 0;
	decimal_count = 0;
	if (**elem == '.')
		decimal_count = parse_decimal(elem, &decimal);
	if ((**elem != ',' && **elem != ' ' && **elem != '\n' && **elem != '\0')
		|| decimal_count == -1)
		return (1);
	*result = sign * convert_to_double(integer, decimal, decimal_count);
	return (0);
}
