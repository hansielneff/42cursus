/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:24:37 by helneff           #+#    #+#             */
/*   Updated: 2022/10/28 19:35:42 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ULONG_MAX (unsigned long) -1

int	ft_atoi(const char *str)
{
	long		result;
	int			sign;
	const long	lmax = (ULONG_MAX - 1) / 2;
	const long	lmin = (ULONG_MAX - 1) / 2 + 1;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		sign = 1 - 2 * (*(str++) == '-');
	while (*str >= '0' && *str <= '9')
	{
		if (result > lmax / 10 || (result == lmax / 10 && *str - '0' > 7))
		{
			if (sign == 1)
				return ((int) lmax);
			else
				return ((int) lmin);
		}
		result = 10 * result + (*(str++) - '0');
	}
	return ((int) result * sign);
}
