/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:27:22 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/14 16:26:57 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "termios.h"

typedef struct s_state
{
	int				pipes[2000];
	int				number_of_pipes;
	int				number_of_execution;
	int				input_file;
	int				input_set;
	int				output_file;
	int				output_set;
	int				continue_interpret;
	char			**envv;
	int				pids[1001];
	int				exit_status;
	struct termios	original_terminal_settings;
}	t_state;

#endif
