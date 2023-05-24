/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:39:30 by helneff           #+#    #+#             */
/*   Updated: 2022/11/16 06:43:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrtostr(char c)
{
	char	*result;

	result = malloc(2);
	if (!result)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
