/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/05/08 13:06:35 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_plane(t_scene_data *scene, const char *elem)
{
	t_plane_data	*plane;

	plane = malloc(sizeof(t_plane_data));
	if (!plane)
		return (1);
	if (parse_num(&elem, &plane->pos.x) || eat_comma(&elem)
		|| parse_num(&elem, &plane->pos.y) || eat_comma(&elem)
		|| parse_num(&elem, &plane->pos.z) || eat_whitespace(&elem)
		|| parse_num(&elem, &plane->dir.x) || eat_comma(&elem)
		|| parse_num(&elem, &plane->dir.y) || eat_comma(&elem)
		|| parse_num(&elem, &plane->dir.z) || eat_whitespace(&elem)
		|| parse_num(&elem, &plane->col.x) || eat_comma(&elem)
		|| parse_num(&elem, &plane->col.y) || eat_comma(&elem)
		|| parse_num(&elem, &plane->col.z) || (*elem && *elem != '\n')
		|| plane->dir.x < -1 || plane->dir.x > 1
		|| plane->dir.y < -1 || plane->dir.y > 1
		|| plane->dir.z < -1 || plane->dir.z > 1
		|| plane->col.x < 0 || plane->col.x > 255
		|| plane->col.y < 0 || plane->col.y > 255
		|| plane->col.z < 0 || plane->col.z > 255)
		return (free(plane), 1);
	plane->next = scene->planes;
	scene->planes = plane;
	plane->id = scene->next_id++;
	return (0);
}
