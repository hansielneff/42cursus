/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:52:34 by helneff           #+#    #+#             */
/*   Updated: 2022/11/14 10:13:31 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_read_buffer
{
	int		fd;
	int		is_empty;
	size_t	index;
	char	data[BUFFER_SIZE + 1];
}	t_read_buffer;

typedef struct s_buffer_list
{
	t_read_buffer			*buffer;
	struct s_buffer_list	*next;
}	t_buffer_list;

char			*get_next_line(int fd);

char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
