/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:36:33 by helneff           #+#    #+#             */
/*   Updated: 2022/10/28 19:38:29 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= -INT_MAX && n <= INT_MAX)
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			ft_putchar_fd(n + '0', fd);
		}
	}
	else if (n == INT_MIN)
	{
		n = n - 2000000000;
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(n, fd);
	}
}
