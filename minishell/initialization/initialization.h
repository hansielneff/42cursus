/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:33:11 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/10 15:47:39 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "../state.h"
# include "../libft/libft.h"

void	initialize(t_state *all, char **envv);
void	enable_raw_mode(struct termios *orig_termios);
void	disable_raw_mode(struct termios *orig_termios);
void	set_signal_handlers(void);
void	initialize_envv(t_state *state, char **envv);
void	clean_state_between_commands(t_state *state);

#endif
