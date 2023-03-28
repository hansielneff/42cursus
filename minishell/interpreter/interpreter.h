/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:16:31 by helneff           #+#    #+#             */
/*   Updated: 2023/03/16 12:58:13 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# include "../parser/parser.h"
# include "../minishell.h"
# include "../state.h"

typedef void	(*t_action)(t_node *node, t_state *state);

void	interpret(t_node *node, t_state *state);

void	invalid_action(t_node *ast, t_state *state);
void	no_action(t_node *node, t_state *state);
void	command_action(t_node *node, t_state *state);
void	pipe_action(t_node *node, t_state *state);
void	redirect_action(t_node *node, t_state *state);

#endif
