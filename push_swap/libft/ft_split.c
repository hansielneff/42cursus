/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:00:07 by helneff           #+#    #+#             */
/*   Updated: 2022/11/15 00:51:29 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_failure(char ***result, size_t i)
{
	while (i-- > 0)
		free((*result)[i]);
	free(*result);
	*result = NULL;
}

static char	*consume_word(char **s, char c)
{
	char	*start;

	while (**s && **s == c)
		++*s;
	start = *s;
	if (*start == '\0')
		return (NULL);
	while (**s && **s != c)
		++*s;
	if (**s != '\0')
		*((*s)++) = '\0';
	return (ft_strdup(start));
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	char		*dynamic_string;
	char		*mut_handle;
	size_t		i;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count((char *)s, c) + 2));
	if (!result)
		return (NULL);
	dynamic_string = ft_strdup(s);
	mut_handle = dynamic_string;
	i = 0;
	while (1)
	{
		result[i++] = consume_word(&mut_handle, c);
		if (!result[i - 1])
		{
			if (ft_strlen(mut_handle))
				handle_failure(&result, i - 1);
			break ;
		}
	}
	free((char *)dynamic_string);
	return (result);
}
