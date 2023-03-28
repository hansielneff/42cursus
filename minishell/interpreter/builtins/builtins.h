/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:09:14 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/24 11:11:34 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../interpreter.h"

void	builtin_echo(t_node *node, t_state *state);
void	builtin_pwd(t_node *node, t_state *state);
void	builtin_cd(t_node *node, t_state *state);
void	builtin_export(t_node *node, t_state *state);
void	builtin_unset(t_node *node, t_state *state);
void	builtin_env(t_node	*node, t_state *state);
void	builtin_exit(t_node *node, t_state *state);

void	export_args(t_node *node, t_state *state);
void	execute_export(t_node *node, t_state *state);
void	print_export_error(char *string);

void	exit_internals(t_node *node, t_state *state);
void	handle_exit_return_value(t_node *node, t_state *state);
int		handle_exit_while_loop(int *index,
			long long int *number, int *is_negative, t_node *node);
int		handle_loop_exit_return_value(t_node *node,
			t_state *state, int *index, char **place);
int		handle_exit_return_value_begin(int *index,
			int *is_negative, t_node *node);

#endif
