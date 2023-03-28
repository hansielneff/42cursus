/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:19:14 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 15:47:38 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../state.h"
# include "../interpreter/interpreter.h"

void	child_execution(t_node	*node, t_state *state,
			int fd_input, int fd_output);
void	execute_program(t_node *node, t_state *state);
void	execute_heredoc(t_node *node, t_state *state);

#endif
