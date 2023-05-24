/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/24 14:01:13 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_light(t_scene_data *scene, const char *elem)
{
	static int	first = 1;

	if (!first)
		return (1);
	first = 0;
	if (parse_num(&elem, &scene->light.pos.x) || eat_comma(&elem)
		|| parse_num(&elem, &scene->light.pos.y) || eat_comma(&elem)
		|| parse_num(&elem, &scene->light.pos.z) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->light.ratio) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->light.col.x) || eat_comma(&elem)
		|| parse_num(&elem, &scene->light.col.y) || eat_comma(&elem)
		|| parse_num(&elem, &scene->light.col.z) || (*elem && *elem != '\n')
		|| scene->light.ratio < 0 || scene->light.ratio > 1
		|| scene->light.col.x < 0 || scene->light.col.x > 255
		|| scene->light.col.y < 0 || scene->light.col.y > 255
		|| scene->light.col.z < 0 || scene->light.col.z > 255)
		return (1);
	return (0);
}
