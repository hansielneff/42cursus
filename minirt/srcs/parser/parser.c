/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:14 by helneff           #+#    #+#             */
/*   Updated: 2023/05/22 12:59:52 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"

#include "parser.h"

static void	skip_identifier(const char **elem)
{
	while (ft_isalpha(**elem))
		(*elem)++;
	while (**elem == ' ')
		(*elem)++;
}

static int	parse_element(t_scene_data *scene, const char *elem)
{
	static const char		*identifiers[]
		= {"C ", "A ", "L ", "sp", "pl", "cy", NULL};
	static const t_parser	parsers[] = \
		{parse_camera, parse_ambient, parse_light,
		parse_sphere, parse_plane, parse_cylinder};
	size_t					i;

	i = 0;
	while (identifiers[i] != NULL)
	{
		if (ft_strncmp(elem, identifiers[i], 2) == 0
			&& (elem[1] == ' ' || elem[2] == ' '))
		{
			skip_identifier(&elem);
			if (parsers[i](scene, elem) != 0)
				return (-1);
			return (0);
		}
		i++;
	}
	return (-1);
}

int	parse_scene_file(t_scene_data *scene, char *file_name)
{
	const int		fd = open(file_name, O_RDONLY);
	const char		*elem = get_next_line(fd);
	int				parse_result;

	if (fd == -1)
		return (-1);
	while (elem != NULL)
	{
		if (elem[0] != '\n')
			parse_result = parse_element(scene, elem);
		free((void *)elem);
		if (parse_result == -1)
		{
			free_scene(scene);
			return (-1);
		}
		elem = get_next_line(fd);
	}
	return (0);
}

void	free_scene(t_scene_data *scene)
{
	void	*curr;
	void	*next;

	curr = scene->spheres;
	while (curr)
	{
		next = ((t_sphere_data *)curr)->next;
		free(curr);
		curr = next;
	}
	curr = scene->planes;
	while (curr)
	{
		next = ((t_plane_data *)curr)->next;
		free(curr);
		curr = next;
	}
	curr = scene->cylinders;
	while (curr)
	{
		next = ((t_cylinder_data *)curr)->next;
		free(curr);
		curr = next;
	}
}
