/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:59:26 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 16:29:44 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		str_len;

	str_len = ft_digitsul(n, 10);
	str = malloc(str_len + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[str_len] = '\0';
	while (n > 0)
	{
		str[--str_len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
