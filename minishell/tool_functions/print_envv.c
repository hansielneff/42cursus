/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_envv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:12:33 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 13:14:21 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../tool_functions/tool_functions.h"
#include "../libft/libft.h"

void	print_export(int *index, t_state *state)
{
	int	index2;

	while (state->envv[*index])
	{
		ft_printf("declare -x ");
		index2 = 0;
		while (state->envv[*index][index2])
		{
			if (state->envv[*index][index2] == '=')
			{
				ft_printf("%s", "=\"");
				++index2;
				while (state->envv[*index][index2])
				{
					ft_printf("%c", state->envv[*index][index2++]);
				}
				ft_printf("%s", "\"");
				break ;
			}
			ft_printf("%c", state->envv[*index][index2++]);
		}
		ft_printf("\n");
		++(*index);
	}
}

void	print_envv(int which, t_state *state)
{
	int	index;

	index = 0;
	if (0 == which)
	{
		while (state->envv[index])
		{
			if (if_exist_equal_sign(state->envv[index]))
			{
				ft_printf("%s\n", state->envv[index]);
			}
			++index;
		}
	}
	if (1 == which)
	{
		print_export(&index, state);
	}
}
