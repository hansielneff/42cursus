/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:11 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/16 12:30:11 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../state.h"

void	not_signal_control_d(t_state *state);
void	signal_control_c(int signal);
void	signal_do_nothing(int signal);
void	signal_control_c_heredoc(int signal);

#endif 
