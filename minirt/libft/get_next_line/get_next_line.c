/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:52:42 by helneff           #+#    #+#             */
/*   Updated: 2022/11/18 09:33:16 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"
#include "../libft.h"

static t_read_buffer	*get_read_buffer(t_buffer_list **buffer_list, int fd)
{
	t_buffer_list	*curr;

	curr = *buffer_list;
	while (curr)
	{
		if (curr->buffer->fd == fd)
			return (curr->buffer);
		curr = curr->next;
	}
	curr = malloc(sizeof(t_buffer_list));
	if (!curr)
		return (NULL);
	curr->buffer = malloc(sizeof(t_read_buffer));
	if (!curr->buffer)
	{
		free(curr);
		return (NULL);
	}
	curr->buffer->data[0] = '\0';
	curr->buffer->is_empty = 1;
	curr->buffer->index = 0;
	curr->buffer->fd = fd;
	curr->next = *buffer_list;
	*buffer_list = (t_buffer_list *)curr;
	return (curr->buffer);
}

static void	free_read_buffer(t_buffer_list **buffer_list, int fd)
{
	t_buffer_list	*curr;
	t_buffer_list	*next;
	t_buffer_list	*prev;

	prev = NULL;
	curr = *buffer_list;
	while (curr)
	{
		if (curr->buffer->fd == fd)
		{
			if (curr->buffer)
				free(curr->buffer);
			next = curr->next;
			free(curr);
			if (prev)
				prev->next = next;
			else
				*buffer_list = next;
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static t_read_buffer	*read_to_buffer(t_read_buffer *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(buffer->fd, buffer->data, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer->is_empty = 0;
		buffer->index = 0;
		buffer->data[bytes_read] = '\0';
	}
	else
		return (NULL);
	return (buffer);
}

static char	*get_line_from_buffer(t_read_buffer *buffer, char **line)
{
	char		*temp;
	const char	*newline_addr = NULL;
	char		temp_char;

	temp_char = '\0';
	while (!newline_addr)
	{
		if ((buffer->is_empty || buffer->data[buffer->index] == '\0')
			&& !read_to_buffer(buffer))
			return (*line);
		newline_addr = ft_strchr(buffer->data + buffer->index, '\n');
		if (newline_addr)
		{
			temp_char = *(newline_addr + 1);
			*((char *)newline_addr + 1) = '\0';
		}
		else
			buffer->is_empty = 1;
		temp = *line;
		*line = ft_strjoin(*line, buffer->data + buffer->index);
		free(temp);
	}
	buffer->index = newline_addr - buffer->data + 1;
	buffer->data[buffer->index] = temp_char;
	return (*line);
}

char	*get_next_line(int fd)
{
	static t_buffer_list	*buffer_list = NULL;
	t_read_buffer			*buffer;
	char					*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	buffer = get_read_buffer(&buffer_list, fd);
	if (!buffer)
		return (NULL);
	if (!get_line_from_buffer(buffer, &line))
		free_read_buffer(&buffer_list, fd);
	return (line);
}
