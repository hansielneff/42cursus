/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:07:02 by helneff           #+#    #+#             */
/*   Updated: 2022/11/14 21:58:59 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*begin;
	const char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	begin = s1;
	end = s1 + ft_strlen(s1);
	while (ft_strchr(set, *begin) && begin < end)
		++begin;
	while (ft_strchr(set, *end) && end > begin)
		--end;
	return (ft_substr(s1, begin - s1, end - begin + 1));
}
