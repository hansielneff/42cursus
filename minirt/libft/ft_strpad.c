/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:43:19 by helneff           #+#    #+#             */
/*   Updated: 2022/11/19 10:13:05 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpad(char *s, char c, size_t amount, int right_side)
{
	char	*result;
	char	*padding;

	if (!s)
		return (NULL);
	if (amount == 0)
		return (s);
	padding = malloc(amount + 1);
	if (!padding)
		return (NULL);
	ft_memset(padding, c, amount);
	padding[amount] = '\0';
	if (right_side)
		result = ft_strjoin(s, padding);
	else
		result = ft_strjoin(padding, s);
	free(padding);
	return (result);
}
