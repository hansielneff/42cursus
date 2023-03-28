/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:47:03 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 12:53:31 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "tool_functions.h"

void	safe_free_string(char **string)
{
	if (string && *string)
		free(*string);
	*string = NULL;
}
