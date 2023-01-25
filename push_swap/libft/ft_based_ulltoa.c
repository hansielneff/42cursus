/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_based_ulltoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:55:23 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 16:29:44 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_based_ulltoa(unsigned long long n, unsigned int base)
{
	char	*str;
	int		str_len;

	if (base < 2 || base > 36)
		return (NULL);
	str_len = ft_digitsul(n, base);
	str = malloc(str_len + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[str_len] = '\0';
	while (n > 0)
	{
		str[--str_len] = "0123456789abcdefghijklmnopqrstuvwxyz"[n % base];
		n /= base;
	}
	return (str);
}
