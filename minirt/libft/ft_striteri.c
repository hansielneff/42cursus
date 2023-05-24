/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:22:47 by helneff           #+#    #+#             */
/*   Updated: 2022/10/27 16:26:52 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	str_len;
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	str_len = ft_strlen(s);
	i = 0;
	while (i < str_len)
	{
		f(i, &s[i]);
		++i;
	}
}
