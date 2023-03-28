/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:08:54 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 17:27:57 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum s_token_type
{
	invalid_token,
	whitespace_token,
	expansion_token,
	raw_str_token,
	expand_str_token,
	word_token,
	pipe_token,
	redirect_in_1_token,
	redirect_in_2_token,
	redirect_out_1_token,
	redirect_out_2_token,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}	t_token;

void	free_token(t_token *token);

#endif
