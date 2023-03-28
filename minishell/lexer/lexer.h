/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:11:09 by helneff           #+#    #+#             */
/*   Updated: 2023/03/09 15:46:42 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "stdlib.h"

# include "tokens/token.h"

# include "../state.h"

typedef struct s_lexer
{
	char	*input;
	char	*index;
	char	curr_char;
}	t_lexer;

t_lexer	*create_lexer(char *str);
t_token	*get_next_token(t_lexer *lexer, t_state *state);
t_token	*peek_next_token(t_lexer *lexer, t_state *state);
void	skip_next_token(t_lexer *lexer, t_state *state);

void	handle_invalid(t_lexer *lexer, t_token *token);
int		read_whitespace(t_lexer *lexer, t_token *token);
int		read_expansion(t_lexer *lexer, t_token *token, t_state *state);
int		read_question_mark(t_lexer *lexer, t_token *token);
int		read_option(t_lexer *lexer, t_token *token);
int		read_single_quote(t_lexer *lexer, t_token *token);
int		read_double_quote(t_lexer *lexer, t_token *token);
int		read_word(t_lexer *lexer, t_token *token);
int		read_raw_str(t_lexer *lexer, t_token *token);
int		read_expand_str(t_lexer *lexer, t_token *token, t_state *state);
int		read_pipe(t_lexer *lexer, t_token *token);
int		read_redirect_in_1(t_lexer *lexer, t_token *token);
int		read_redirect_in_2(t_lexer *lexer, t_token *token);
int		read_redirect_out_1(t_lexer *lexer, t_token *token);
int		read_redirect_out_2(t_lexer *lexer, t_token *token);

#endif
