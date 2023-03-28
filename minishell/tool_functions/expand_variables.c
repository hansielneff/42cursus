/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:46:13 by helneff           #+#    #+#             */
/*   Updated: 2023/03/23 19:45:26 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include "../minishell.h"
#include "../tool_functions/tool_functions.h"

static char	*parse_env_var(char *var_name, t_state *state)
{
	char	*var_value;
	char	*var_wo_equal;
	char	*var_w_equal;

	var_value = (void *) 0;
	var_wo_equal = variable_up_to_equal_sign(var_name);
	var_w_equal = ft_strjoin(var_wo_equal, "=");
	if (exist_envv_variable(var_wo_equal, 1, state))
		var_value = ft_strdup("");
	else if (exist_envv_variable(var_w_equal, 0, state))
		var_value = get_var_from_envv(var_wo_equal, state);
	else
		var_value = ft_strdup("");
	safe_free_string(&var_wo_equal);
	safe_free_string(&var_w_equal);
	return (var_value);
}

static void	expand_var(char	**result,
	char *var_begin, char *var_end, t_state *state)
{
	char	*var_name;
	char	*var_value;
	char	*temp;

	var_name = ft_substr(var_begin, 0, var_end - var_begin);
	if (var_name[1] == '?')
		var_value = ft_itoa(state->exit_status);
	else
		var_value = parse_env_var(var_name + 1, state);
	temp = *result;
	*result = ft_strsubst(*result, var_name, var_value);
	free(temp);
	free(var_name);
	free(var_value);
}

char	*expand_variables(char *string, t_state *state)
{
	char	*result;
	char	*var_begin;
	char	*var_end;

	result = ft_strdup(string);
	if (!ft_strncmp("$", result, ft_strlen(result)))
		return (result);
	var_begin = ft_strchr(result, '$');
	var_end = var_begin;
	while (var_begin)
	{
		var_end = var_begin + 1;
		while (ft_isalnum(*var_end))
			var_end++;
		if (var_begin[1] == '?')
			var_end++;
		expand_var(&result, var_begin, var_end, state);
		var_begin = ft_strchr(result, '$');
	}
	return (result);
}
