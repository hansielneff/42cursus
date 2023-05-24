/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/24 13:58:41 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_ambient(t_scene_data *scene, const char *elem)
{
	static int	first = 1;

	if (!first)
		return (1);
	first = 0;
	if (parse_num(&elem, &scene->ambient.ratio) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->ambient.col.x) || eat_comma(&elem)
		|| parse_num(&elem, &scene->ambient.col.y) || eat_comma(&elem)
		|| parse_num(&elem, &scene->ambient.col.z) || (*elem && *elem != '\n')
		|| scene->ambient.ratio < 0 || scene->ambient.ratio > 1
		|| scene->ambient.col.x < 0 || scene->ambient.col.x > 255
		|| scene->ambient.col.y < 0 || scene->ambient.col.y > 255
		|| scene->ambient.col.z < 0 || scene->ambient.col.z > 255)
		return (1);
	return (0);
}
