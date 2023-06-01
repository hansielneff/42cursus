/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_based_lltoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:55:23 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 16:29:34 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_based_lltoa(long long n, int base)
{
	char	*str;
	int		str_len;
	int		is_negative;

	if (base < 2 || base > 36)
		return (NULL);
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	else
		n *= -1;
	str_len = ft_digitsl(n, base) + is_negative;
	str = malloc(str_len + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	if (is_negative)
		str[0] = '-';
	str[str_len] = '\0';
	while (n < 0)
	{
		str[--str_len] = "0123456789abcdefghijklmnopqrstuvwxyz"[-n % base];
		n /= base;
	}
	return (str);
}
