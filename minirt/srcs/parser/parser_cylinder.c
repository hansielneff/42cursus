/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/12 19:02:33 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_cylinder(t_scene_data *scene, const char *elem)
{
	t_cylinder_data	*cylinder;

	cylinder = malloc(sizeof(t_cylinder_data));
	if (!cylinder)
		return (1);
	if (parse_num(&elem, &cylinder->pos.x) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->pos.y) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->pos.z) || eat_whitespace(&elem)
		|| parse_num(&elem, &cylinder->dir.x) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->dir.y) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->dir.z) || eat_whitespace(&elem)
		|| parse_num(&elem, &cylinder->diameter) || eat_whitespace(&elem)
		|| parse_num(&elem, &cylinder->height) || eat_whitespace(&elem)
		|| parse_num(&elem, &cylinder->col.x) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->col.y) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->col.z) || (*elem && *elem != '\n')
		|| cylinder->dir.x < -1 || cylinder->dir.x > 1 || cylinder->dir.y < -1
		|| cylinder->dir.y > 1 || cylinder->dir.z < -1 || cylinder->dir.z > 1
		|| cylinder->col.x < 0 || cylinder->col.x > 255
		|| cylinder->col.y < 0 || cylinder->col.y > 255
		|| cylinder->col.z < 0 || cylinder->col.z > 255)
		return (free(cylinder), 1);
	cylinder->next = scene->cylinders;
	scene->cylinders = cylinder;
	return (0 * (cylinder->id = scene->next_id++));
}
