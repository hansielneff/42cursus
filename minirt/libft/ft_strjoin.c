/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:00:16 by helneff           #+#    #+#             */
/*   Updated: 2022/11/14 18:08:58 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	result_size;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	result_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(result_size);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, result_size);
	ft_strlcat(result, s2, result_size);
	return (result);
}
