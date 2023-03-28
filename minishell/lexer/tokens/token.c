/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:14:20 by helneff           #+#    #+#             */
/*   Updated: 2023/02/24 16:16:13 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "token.h"

void	free_token(t_token *token)
{
	if (token)
		free(token->value);
	free(token);
}
